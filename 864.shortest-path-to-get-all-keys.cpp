/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */

// @lc code=start
const int MOVES[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  int shortestPathAllKeys(vector<string>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    vector<set<int>> visit(rows * cols);

    int startR;
    int startC;
    int keys = 0;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(grid[i][j] == '@') {
          startR = i;
          startC = j;
        } else if(islower(grid[i][j])) {
          keys = max(keys, grid[i][j] - 'a' + 1);
        } 
      }
    }

    int step = 0;
    queue<pair<int, int>> q;
    q.push({0, startR * cols + startC});
    visit[startR * cols + startC].insert(0);
    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto [state, position] = q.front();
        q.pop();
        if(state == (1 << keys) - 1) return step;
        int currentR = position / cols;
        int currentC = position % cols;
        for(int m = 0; m < 4; ++m) {
          int newR = currentR + MOVES[m][0];
          int newC = currentC + MOVES[m][1];
          if(newR < 0 || newC < 0 || newR >= rows || newC >= cols) continue; // out of bound
          if(grid[newR][newC] == '#') continue; // wall
          if(isupper(grid[newR][newC]) && !(state & (1 << (grid[newR][newC] - 'A')))) continue; // lock without key
          int newState = state;
          int newPosition = newR * cols + newC;
          if(islower(grid[newR][newC])) newState |= (1 << (grid[newR][newC] - 'a'));
          if(visit[newPosition].count(newState)) continue; // visited
          q.push({newState, newPosition});
          visit[newPosition].insert(newState);
        }
      }
      step += 1;
    }

    return -1;
  }
};

// Accepted
// 35/35 cases passed (108 ms)
// Your runtime beats 51.68 % of cpp submissions
// Your memory usage beats 55.37 % of cpp submissions (22.1 MB)
// @lc code=end

