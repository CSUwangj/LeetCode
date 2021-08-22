/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  vector<int> rows = vector<int>(9), cols = vector<int>(9), squares = vector<int>(9);
  void init(vector<vector<char>>& board) {
    for(int i = 0; i < 81; ++i){
      int row = i % 9;
      int col = i / 9;
      int square = i % 9 / 3 * 3 + i / 9 / 3;
      if(board[row][col] == '.') continue;
      rows[row] |= (1 << (board[row][col] - '0'));
      cols[col] |= (1 << (board[row][col] - '0'));
      squares[square] |= (1 << (board[row][col] - '0'));
    }
  }
  bool dfs(vector<vector<char>>& board, int pos) {
    if(pos == 81) return true;
    int row = pos % 9;
    int col = pos / 9;
    int square = pos % 9 / 3 * 3 + pos / 9 / 3;
    if(board[row][col] != '.') return dfs(board, pos+1);
    for(int i = 1; i < 10; ++i) {
      if(rows[row] & (1 << i) ||
        cols[col] & (1 << i) ||
        squares[square] & (1 << i)) continue;
      rows[row] |= (1 << i);
      cols[col] |= (1 << i);
      squares[square] |= (1 << i);
      if(dfs(board, pos+1)) {
        board[row][col] = i+'0';
        return true;
      }
      rows[row] ^= (1 << i);
      cols[col] ^= (1 << i);
      squares[square] ^= (1 << i);
    }
    return false;
  }
public:
  void solveSudoku(vector<vector<char>>& board) {
    init(board);
    dfs(board, 0);
  }
};

// Accepted
// 6/6 cases passed (4 ms)
// Your runtime beats 98.8 % of cpp submissions
// Your memory usage beats 83.27 % of cpp submissions (6.4 MB)
// @lc code=end

