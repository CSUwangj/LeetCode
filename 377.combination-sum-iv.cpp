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
// 15/15 cases passed (4 ms)
// Your runtime beats 46.34 % of cpp submissions
// Your memory usage beats 65.95 % of cpp submissions (6.6 MB)
// @lc code=end

