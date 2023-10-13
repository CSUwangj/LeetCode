/*
 * @lc app=leetcode id=2328 lang=cpp
 *
 * [2328] Number of Increasing Paths in a Grid
 */

// @lc code=start
class Solution {
  const int MOD = 1e9 + 7;
  const int MOVES[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int rows;
  int cols;
  int solve(
    int row,
    int col,
    int parent,
    const vector<vector<int>>& grid,
    vector<vector<int>> &dp
  ) {
    if(row < 0 || row >= rows) return 0;
    if(col < 0 || col >= cols) return 0;
    if(grid[row][col] <= parent) return 0;
    if(dp[row][col] != -1) return dp[row][col];

    int result = 1;
    for(int m = 0; m < 4; ++m) {
      int newRow = row + MOVES[m][0];
      int newCol = col + MOVES[m][1];
      result += solve(newRow, newCol, grid[row][col], grid, dp);
      result %= MOD;
    }
    dp[row][col] = result;
    return result;
  }
public:
  int countPaths(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid.front().size();
    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(dp[r][c] == -1) solve(r, c, -1, grid, dp);
      }
    }

    int answer = 0;
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        answer += dp[r][c];
        answer %= MOD;
      }
    }

    return answer;
  }
};

// Accepted
// 36/36 cases passed (292 ms)
// Your runtime beats 75.49 % of cpp submissions
// Your memory usage beats 80.56 % of cpp submissions (43.4 MB)
// @lc code=end

