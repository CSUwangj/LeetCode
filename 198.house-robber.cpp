/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
  int rob(vector<int>& nums) {
    int dp[2] = {};
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
      int parity = (i & 1);
      dp[parity] = max(dp[!parity], dp[parity] + nums[i]);
    }
    return max(dp[0], dp[1]);
  }
};

// Accepted
// 68/68 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.98 % of cpp submissions (7.7 MB)
// @lc code=end
