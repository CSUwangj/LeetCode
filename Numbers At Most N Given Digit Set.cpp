// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  uint dp[12] = {0};
  uint dp2[12] = {0};
  uint prefix[10] = {0};
  vector<int> digit;
public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    int len = to_string(n).size();
    for(auto &d : digits) {
      digit.push_back(d[0] - '0');
    }
    sort(digit.begin(), digit.end());
    int curIndex = 0;
    for(int i = 1; i < 10; ++i) {
      if(curIndex < digit.size() && i >= digit[curIndex]) {
        prefix[i] = prefix[i-1] + 1;
        curIndex += 1;
      } else {
        prefix[i] = prefix[i-1];
      }
    }
    dp[0] = 1;
    for(int i = 1; i < len; ++i) {
      dp[i] = dp[i-1] * digit.size();
    }
    int curNum = n;
    dp2[0] = 1;
    for(int i = 1; i <= len; ++i) {
      int curDigit = curNum % 10;
      curNum /= 10;
      if(curDigit == 0) dp2[i] = 0;
      else {
        dp2[i] = prefix[curDigit-1] * dp[i-1];
        if(find(digit.begin(), digit.end(), curDigit) != digit.end()){
          dp2[i] += dp2[i-1];
        }
      }
    }
    int answer = dp2[len];
    for(int i = 1; i < len; ++i) {
      answer += dp[i];
    }
    return answer;
  }
};

int main() {
  vector<tuple<vector<string>, int>> data = {
    {{"1","3","5","7"}, 100},
    {{"1","4","9"}, 1000000000},
    {{"7"}, 8},
    {{"3", "4", "8"}, 8}
  };
  for(auto &[digits, n]: data) {
    auto sol = Solution();
    auto ans = sol.atMostNGivenDigitSet(digits, n);
    cout << ans << endl;
  } 
  return 0;
}