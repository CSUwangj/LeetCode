/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    double dp[query_row + 1];
    dp[0] = poured;
    for(int row = 1; row <= query_row; ++row) {
      dp[row] = max(0.0, dp[row - 1] - 1) / 2;
      for(int col = row - 1; col > 0; --col) {
        dp[col] = max(0.0, dp[col] - 1) / 2 + max(0.0, dp[col - 1] - 1) / 2;
      }
      dp[0] = max(0.0, dp[0] - 1) / 2;
    }
    return min(dp[query_glass], 1.0);
  }
};

// Accepted
// 312/312 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 76.54 % of cpp submissions (6.3 MB)
// @lc code=end

