/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
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
  int cherryPickup(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    int dp[rows][cols + 2][cols + 2];
    memset(dp, -1, sizeof(dp));
    dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];
    for(int row = 1; row < rows; ++row) {
      for(int col1 = 0; col1 < cols - 1; ++col1) {
        for(int col2 = col1; col2 < cols; ++col2) {
          int result = -1;
          for(int prev1 = max(col1 - 1, 0); prev1 < min(cols, col1 + 2); ++prev1) {
            for(int prev2 = max(col2 - 1, 0); prev2 < min(cols, col2 + 2); ++prev2) {
              result = max(result, dp[row - 1][prev1][prev2]);
            }
          }
          if(result == -1) continue;
          dp[row][col1][col2] = result + grid[row][col1];
          if(col1 != col2) {
            dp[row][col1][col2] += grid[row][col2];
          }
        }
      }
    }
    int answer = *max_element((int*)dp[row - 1], (int*)dp[row - 1] + sizeof(dp[0]));
    return answer;
  }
};

// Accepted
// 58/58 cases passed (25 ms)
// Your runtime beats 88.71 % of cpp submissions
// Your memory usage beats 89.92 % of cpp submissions (9.5 MB)
// @lc code=end
