/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution {
  pair<int, int> getCoordinate(int n, int pos) {
    int rowOffset = (pos - 1) / n;
    int colOffset = (pos - 1) % n;

    int row = n - 1 - rowOffset;
    int col = rowOffset % 2 ? n - 1 - colOffset : colOffset;
    return {row, col};
  }
public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> visits(n * n + 1);

    queue<int> q;
    q.push(1);
    visits[1] = true;
    int step = 0;

    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        int cur = q.front();
        // cout << cur << ':' << endl;
        if(cur == n * n) return step;
        q.pop();
        for(int i = 1; i < 7; ++i) {
          int next = cur + i;
          if(next > n * n) break;
          auto [row, col] = getCoordinate(n, next);
          // cout << row << ' ' << col;
          if(board[row][col] != -1) {
            next = board[row][col];
          }
          // cout << ' ' << next << endl;
          if(visits[next]) continue;
          visits[next] = true;
          q.push(next);
        }
      }
      step += 1;
    }

    return -1;
  }
};

// Accepted
// 214/214 cases passed (33 ms)
// Your runtime beats 53.16 % of cpp submissions
// Your memory usage beats 73 % of cpp submissions (12.9 MB)
// @lc code=end

