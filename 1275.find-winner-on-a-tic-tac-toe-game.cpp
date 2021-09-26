/*
 * @lc app=leetcode id=1275 lang=cpp
 *
 * [1275] Find Winner on a Tic Tac Toe Game
 */

// @lc code=start
class Solution {
  int board[3][3] = {};
  int checkWinner() {
    for(int w = 1; w < 3; ++w) {
      if (board[0][0] == w && board[1][0] == w && board[2][0] == w ||
          board[0][1] == w && board[1][1] == w && board[2][1] == w ||
          board[0][2] == w && board[1][2] == w && board[2][2] == w ||
          board[0][0] == w && board[0][1] == w && board[0][2] == w ||
          board[1][0] == w && board[1][1] == w && board[1][2] == w ||
          board[2][0] == w && board[2][1] == w && board[2][2] == w ||
          board[0][0] == w && board[1][1] == w && board[2][2] == w ||
          board[0][2] == w && board[1][1] == w && board[2][0] == w
      ) {
        return w;
      }
    }
    return 0;
  }
public:
  string tictactoe(vector<vector<int>>& moves) {
    int len = moves.size();
    for(int i = 0; i < len; i += 2) {
      board[moves[i][0]][moves[i][1]] = 1;
    }
    for(int i = 1; i < len; i += 2) {
      board[moves[i][0]][moves[i][1]] = 2;
    }
    int winner = checkWinner();
    if(winner) {
      return winner == 1 ? "A" : "B";
    }
    return moves.size() == 9 ? "Draw" : "Pending";
  }
};

// Accepted
// 100/100 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 96.15 % of cpp submissions (8.1 MB)
// @lc code=end

