/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> LIS(nums.size(), 1);
    vector<int> ways(nums.size(), 1);
    for(int i = 1; i < nums.size(); ++i) {
      for(int j = 0; j < i; ++j) {
        if(nums[j] < nums[i] && LIS[j]+1 > LIS[i]) {
          ways[i] = ways[j];
          LIS[i] = LIS[j] + 1;
        } else if(nums[j] < nums[i] && LIS[j]+1 == LIS[i]) {
          ways[i] += ways[j];  
        } 
      }
    }
    int LISLength = *max_element(LIS.begin(), LIS.end());
    int ans = 0;
    for(int i = 0; i < nums.size(); ++i) {
      if(LIS[i] == LISLength) ans += ways[i];
    }
    return ans;
  }
};

// Accepted
// 223/223 cases passed (217 ms)
// Your runtime beats 43.24 % of cpp submissions
// Your memory usage beats 66.65 % of cpp submissions (13.2 MB)
// @lc code=end

