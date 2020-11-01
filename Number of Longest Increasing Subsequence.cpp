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
  int findNumberOfLIS(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> dp(nums.size(), 1), ways(nums.size(), 1);
    for(int i = 1; i < nums.size(); ++i) {
      for(int j = 0; j < i; ++j) {
        if(nums[i] > nums[j]) {
          if(dp[j]+1 > dp[i]) {
            dp[i] = dp[j]+1;
            ways[i] = ways[j];
          } else if(dp[j]+1 == dp[i]) {
            ways[i] += ways[j];
          }
        }
      }
    }
    int LISLength = *max_element(dp.begin(), dp.end()), ans = 0;
    for(int i = 0; i < nums.size(); ++i) {
      if(dp[i] == LISLength) ans += ways[i];
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> data = {
    {1,3,5,4,7},
    {2,2,2,2,2},
    {1,3,5,7,2,4,6},
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.findNumberOfLIS(data);
    cout << ans << endl;
  } 
  return 0;
}