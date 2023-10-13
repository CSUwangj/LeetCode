/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
    vector<int> dp(m*n);
    dp[0] = 1;
    for(int i = 1; i < m*n; ++i) {
      if(obstacleGrid[i/n][i%n] == 1) continue;
      if(i >= n) dp[i] += dp[i-n];
      if(i % n != 0) dp[i] += dp[i-1];
    }
    return dp.back();
  }
};

// Accepted
// 41/41 cases passed (5 ms)
// Your runtime beats 28.03 % of cpp submissions
// Your memory usage beats 61.67 % of cpp submissions (7.7 MB)
// @lc code=end

