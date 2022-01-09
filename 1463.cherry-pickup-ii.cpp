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
const int moves[9][2] = {
  {-1, -1},
  {-1, 0},
  {-1, 1},
  {0, -1},
  {0, 0},
  {0, 1},
  {1, -1},
  {1, 0},
  {1, 1},
};
class Solution {
public:
  int cherryPickup(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    // col1 * cols + col2
    int dp[2][cols * cols];
    memset(dp, -1, sizeof(dp));
    // 0 * cols + cols - 1
    dp[0][cols - 1] = grid[0][0] + grid[0][cols - 1];
    for(int row = 0; row < rows - 1; ++row) {
      int parity = (row & 1);
      for(int index = 0; index < cols * cols; ++index) {
        if(dp[parity][index] == -1) continue;
        int col1 = index / cols;
        int col2 = index % cols;
        for(int m = 0 ; m < 9; ++m) {
          int newCol1 = col1 + moves[m][0];
          int newCol2 = col2 + moves[m][1];
          int newIndex = newCol1 * cols + newCol2;
          if(newCol1 < 0 || newCol2 < 0 || newCol1 >= cols || newCol2 >= cols) continue;
          if(newCol1 > newCol2) continue;
          int cherries = grid[row + 1][newCol1];
          if(newCol2 != newCol1) {
            cherries += grid[row + 1][newCol2];
          }
          dp[parity ^ 1][newIndex] = max(dp[parity ^ 1][newIndex], dp[parity][index] + cherries);
        }
      }
    }
    auto resultSet = dp[((rows & 1) ^ 1)];
    int answer = *max_element(resultSet, resultSet + cols * cols);
    return answer;
  }
};

// Accepted
// 58/58 cases passed (57 ms)
// Your runtime beats 50.61 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (8.2 MB)
// @lc code=end
