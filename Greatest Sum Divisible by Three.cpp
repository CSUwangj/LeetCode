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
  int maxSumDivThree(vector<int>& nums) {
    vector<int> one;
    vector<int> two;
    int three = 0;
    for(auto num : nums) {
      if(num % 3 == 0) {
        three += num;
      } else if(num % 3 == 1) {
        one.push_back(num);
      } else {
        two.push_back(num);
      }
    }
    sort(one.begin(), one.end(), greater<int>());
    sort(two.begin(), two.end(), greater<int>());
    
    int maxOfOneAndTwo = 0;
    for(int i = 0; i+2 < one.size(); i += 3) {
      maxOfOneAndTwo += one[i] + one[i+1] + one[i+2];
    }
    for(int i = 0; i+2 < two.size(); i += 3) {
      maxOfOneAndTwo += two[i] + two[i+1] + two[i+2];
    }
    if(one.size() > 0 && two.size() > 0) {
      int cur = one[0] + two[0];
      for(int i = 1; i+2 < one.size(); i += 3) {
        cur += one[i] + one[i+1] + one[i+2];
      }
      for(int i = 1; i+2 < two.size(); i += 3) {
        cur += two[i] + two[i+1] + two[i+2];
      }
      maxOfOneAndTwo = max(cur, maxOfOneAndTwo);
    }
    if(one.size() > 1 && two.size() > 1) {
      int cur = one[0] + two[0] + one[1] + two[1];
      for(int i = 2; i+2 < one.size(); i += 3) {
        cur += one[i] + one[i+1] + one[i+2];
      }
      for(int i = 2; i+2 < two.size(); i += 3) {
        cur += two[i] + two[i+1] + two[i+2];
      }
      maxOfOneAndTwo = max(cur, maxOfOneAndTwo);
    }
    return three + maxOfOneAndTwo;
  }
};

int main() {
  vector<vector<int>> data = {
    {3,6,5,1,8},
    {1,2,3,4,4}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.maxSumDivThree(data);
    cout << ans << endl;
  } 
  return 0;
}