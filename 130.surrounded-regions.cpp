/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int rows;
  int cols;
  vector<vector<bool>> vis;
  void dfs(int row, int col, vector<vector<char>>& board) {
    vis[row][col] = true;
    board[row][col] = 'A';
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols) continue;
      if(vis[newRow][newCol] || board[newRow][newCol] == 'X') continue;
      dfs(newRow, newCol, board);
    }
  }
public:
  void solve(vector<vector<char>>& board) {
    rows = board.size();
    cols = board.front().size();
    vis.resize(rows, vector<bool>(cols));
    for(int i = 0; i < cols; ++i) {
      if(!vis[0][i] && board[0][i] == 'O') dfs(0, i, board);
      if(!vis[rows - 1][i] && board[rows - 1][i] == 'O') dfs(rows - 1, i, board); 
    }
    for(int i = 0; i < rows; ++i) {
      if(!vis[i][0] && board[i][0] == 'O') dfs(i, 0, board);
      if(!vis[i][cols - 1] && board[i][cols - 1] == 'O') dfs(i, cols - 1, board);
    }
    for(auto &row : board) {
      for(auto &c : row) {
        c = (c == 'A' ? 'O' : 'X');
      }
    }
  }
};

// Accepted
// 58/58 cases passed (12 ms)
// Your runtime beats 84.68 % of cpp submissions
// Your memory usage beats 44.1 % of cpp submissions (10.2 MB)
// @lc code=end

