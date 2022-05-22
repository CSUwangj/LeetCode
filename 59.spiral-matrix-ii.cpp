/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
  int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int sat(vector<vector<int>> &result, int newH, int newW, int n) {
    return newH >= 0 && newW >= 0 && newH < n && newW < n && !result[newH][newW];
  }
public:
  vector<vector<int>> generateMatrix(int n) {
    auto result = vector<vector<int>>(n, vector<int>(n, 0));
    result[0][0] = 1;
    if(n == 1) return result;
    int h = 0;
    int w = 1;
    int direction = 0;
    while(true) {
      result[h][w] = result[h-move[direction][0]][w-move[direction][1]] + 1;
      int turn = 0;
      while(turn < 4 && !sat(result, h + move[direction][0], w + move[direction][1], n)) {
        direction = (direction + 1) % 4;
        turn += 1;
      }
      if(turn == 4) break;
      h += move[direction][0];
      w += move[direction][1];
    }
    return result;
  }
};

// Accepted
// 20/20 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 85.87 % of cpp submissions (6.5 MB)
// @lc code=end
