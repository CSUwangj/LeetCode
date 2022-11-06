/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
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
  vector<int> findBall(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    if(cols == 1) return { -1 };
    vector<vector<int>> result(2, vector<int>(cols));
    for(int i = 0; i < cols; ++i) {
      result[rows & 1][i] = i;
    }
    for(int row = rows - 1; row >= 0; --row) {
      int curRow = row & 1;
      for(int j = 1; j < cols - 1; ++j) {
        if(grid[row][j] == grid[row][j + grid[row][j]]) {
          result[curRow][j] = result[curRow ^ 1][j + grid[row][j]];
        } else {
          result[curRow][j] = -1;
        }
      }
      if(grid[row][0] == -1 || grid[row][1] != grid[row][0]) {
        result[curRow][0] = -1;
      } else {
        result[curRow][0] = result[curRow ^ 1][1];
      }
      if(grid[row][cols - 1] == 1 || grid[row][cols - 1] != grid[row][cols - 2]) {
        result[curRow][cols - 1] = -1;
      } else {
        result[curRow][cols - 1] = result[curRow ^ 1][cols - 2];
      }
    }
    return result[0];
  }
};

// Accepted
// 64/64 cases passed (48 ms)
// Your runtime beats 65.19 % of cpp submissions
// Your memory usage beats 19.11 % of cpp submissions (13.3 MB)
// @lc code=end

