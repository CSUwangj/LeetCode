/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    int rows = board.size();
    int cols = board[0].size();
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        for(int row = max(0, i-1); row <= min(rows-1, i+1); ++row) {
          for(int col = max(0, j-1); col <= min(cols-1, j+1); ++col) {
            board[i][j] += ((board[row][col] & 1) << 1);
          }
        }
        board[i][j] -= ((board[i][j] & 1) << 1);
      }
    }
    for(auto &row : board) {
      for(auto &cell : row) {
        if(cell > 4 && cell < 8) cell = 1;
        else cell = 0;
      }
    }
  }
};

// Accepted
// 22/22 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 20.27 % of cpp submissions (7 MB)
// @lc code=end
