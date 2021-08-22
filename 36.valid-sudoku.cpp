/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool visRow[9][9] = {};
  bool visCol[9][9] = {};
  bool visBox[9][9] = {};
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for(int row = 0; row < 9; ++row) {
      for(int col = 0; col < 9; ++col) {
        int box = row / 3 * 3 + col / 3;
        int digit = board[row][col] == '.' ? -1 : board[row][col] - '1';
        if(digit == -1) continue;
        if(visRow[row][digit] || visCol[col][digit] || visBox[box][digit]) return false;
        visRow[row][digit] = true;
        visCol[col][digit] = true;
        visBox[box][digit] = true;
      }
    }
    return true;
  }
};

// Accepted
// 507/507 cases passed (12 ms)
// Your runtime beats 98.39 % of cpp submissions
// Your memory usage beats 72.54 % of cpp submissions (18 MB)
// @lc code=end

