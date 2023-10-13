/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1);
    dp[0] = 1;
    for(int i = 1; i <= target; ++i) {
      for(auto num : nums) {
        if(num <= i && INT_MAX - dp[i] > dp[i - num]) dp[i] += dp[i - num];
      }
    }
    return dp[target];
  }
};

// Accepted
// 15/15 cases passed (3 ms)
// Your runtime beats 50.37 % of cpp submissions
// Your memory usage beats 46.24 % of cpp submissions (6.7 MB)
// @lc code=end

