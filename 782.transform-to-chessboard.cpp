/*
 * @lc app=leetcode id=782 lang=cpp
 *
 * [782] Transform to Chessboard
 */

// @lc code=start
class Solution {
public:
  int movesToChessboard(vector<vector<int>>& board) {
    int n = board.size();
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(board[0][0] ^ board[0][j] ^ board[i][0] ^ board[i][j]) return - 1;
      }
    }
    int rowSum = 0;
    int colSum = 0;
    int rowSwap = 0;
    int colSwap = 0;
    for(int i = 0; i < n; ++i) {
      rowSum += board[0][i];
      colSum += board[i][0];
      rowSwap += board[i][0] == (i & 1);
      colSwap += board[0][i] == (i & 1);
    }
    if(rowSum != n / 2 && rowSum != (n + 1) / 2) return -1;
    if(colSum != n / 2 && colSum != (n + 1) / 2) return -1;
    if(n & 1) {
      if(colSwap & 1) colSwap = n - colSwap;
      if(rowSwap & 1) rowSwap = n - rowSwap;
    } else {
      if(colSwap * 2 > n) colSwap = n - colSwap;
      if(rowSwap * 2 > n) rowSwap = n - rowSwap;
    }
    return (colSwap + rowSwap) / 2;
  }
};

// Accepted
// 124/124 cases passed (4 ms)
// Your runtime beats 96.43 % of cpp submissions
// Your memory usage beats 98.21 % of cpp submissions (10 MB)
// @lc code=end

