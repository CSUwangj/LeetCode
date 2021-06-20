/*
 * @lc app=leetcode id=778 lang=cpp
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
using ti = tuple<int, int, int>;
class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    int size = grid.size();
    int maxTime = size * size - 1;
    if(grid.front().front() == maxTime || grid.back().back() == maxTime) return maxTime;
    vector<vector<bool>> vis(size, vector<bool>(size));
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    pq.push({grid[0][0], 0, 0});
    vis[0][0] = true;
    while(pq.size()) {
      auto [time, row, col] = pq.top();
      pq.pop();
      if(row == size - 1 && col == size - 1) return time;
      for(int i = 0; i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newRow >= size || newCol < 0 || newCol >= size) continue;
        if(vis[newRow][newCol]) continue;
        vis[newRow][newCol] = true;
        pq.push({max(time, grid[newRow][newCol]), newRow, newCol});
      }
    }
    return -1;
  }
};
// @lc code=end

