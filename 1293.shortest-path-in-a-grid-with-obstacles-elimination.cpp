/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
const int8_t moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
bool vis[80][40][40];
struct State {
  int16_t step;
  int8_t rest;
  int8_t row;
  int8_t column;
  State(int16_t step = 0, int8_t rest = 0, int8_t row = 0, int8_t column = 0) : 
    step(step), rest(rest), row(row), column(column) { }
  bool operator<(const State& other) const {
    return step > other.step || (step == other.step && rest < other.rest);
  }
};
class Solution {
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int8_t rows = grid.size();
    int8_t cols = grid.front().size();
    if(k >= rows + cols - 3) return rows + cols - 2;
    memset(vis, 0, sizeof(vis[0]) * (k + 1));
    priority_queue<State> pq;
    pq.push(State(0, k, 0, 0));
    vis[k][0][0] = true;
    while(pq.size()) {
      auto [step, rest, row, col] = pq.top();
      // cout << step << " " << rest << " " << row << " " << col <<endl;
      pq.pop();
      if(row == rows - 1 && col == cols - 1) return step;
      for(int i = 0; i < 4; ++i) {
        int8_t newRow = row + moves[i][0];
        int8_t newCol = col + moves[i][1];
        int8_t newRest = rest;
        if(newRow >= rows || newCol >= cols || newRow < 0 || newCol < 0) continue;
        newRest -= grid[newRow][newCol];
        // cout << newRest << ' ' << newRow << ' ' << newCol <<endl;
        if(newRest < 0 || vis[newRest][newRow][newCol]) {
          continue;
        }
        pq.push(State(step + 1, newRest, newRow, newCol));
        vis[newRest][newRow][newCol] = true;
      }
    }
    return -1;
  }
};

// Accepted
// 52/52 cases passed (10 ms)
// Your runtime beats 98.78 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (7.9 MB)
// @lc code=end

