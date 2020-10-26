// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    vector<string> tmp;
    string answer = "";
    for (auto i : nums) {
      tmp.push_back(to_string(i));
    }
    sort(tmp.begin(), tmp.end(), [](const string& a, const string& b) {
      for(int i = 0; i < min(a.length(), b.length()); ++i) {
        if(a[i] != b[i]) return a[i] > b[i];
      }
      if(a.length() == b.length()) return true;
      if(a.length() > b.length()) {
        return a[a.length()-1] >= a[0];
      }
      return b[a.length()-1] <= a[0];
    });
    for (auto &s : tmp) {
      answer += s;
    }
    return answer;
  }
};

int main() {
  vector<vector<int>> data = {
    {3,30,34,5,9}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.largestNumber(data);
    cout << ans << endl;
  } 
  return 0;
}