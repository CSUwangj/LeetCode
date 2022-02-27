/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    int dp[2][cols];
    for(int i = 0; i < cols; ++i) {
      dp[0][i] = grid[0][i];
      if(i) dp[0][i] += dp[0][i - 1];
    }
    for(int i = 1; i < rows; ++i) {
      int parity = (i & 1);
      dp[parity][0] = dp[!parity][0] + grid[i][0];
      for(int j = 1; j < cols; ++j) {
        dp[parity][j] = min(dp[!parity][j], dp[parity][j - 1]) + grid[i][j];
      }
    }
    return dp[!(rows & 1)][cols - 1];
  }
};

// Accepted
// 61/61 cases passed (14 ms)
// Your runtime beats 44.57 % of cpp submissions
// Your memory usage beats 86.95 % of cpp submissions (9.7 MB)
// @lc code=end
