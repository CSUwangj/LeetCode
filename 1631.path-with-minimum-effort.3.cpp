/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
auto speedup = []() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

using pi = pair<int, int>;
bool vis[2][100][100];
int efforts[2][100][100];
class Solution {
  int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    memset(vis, 0, sizeof(vis));
    int rows = heights.size();
    int cols = heights.front().size();
    priority_queue<pi, vector<pi>, greater<pi>> q[2];
    q[0].push({0, 0});
    q[1].push({0, rows * cols - 1});
    while(true) {
      for(int parity = 0; parity < 2; ++parity) {
        while(q[parity].size()) {
          auto [effort, pos] = q[parity].top();
          q[parity].pop();
          int row = pos / cols;
          int col = pos % cols;
          if(vis[!parity][row][col]) return max(effort, efforts[!parity][row][col]);
          if(vis[parity][row][col]) continue;
          vis[parity][row][col] = true;
          efforts[parity][row][col] = effort;
          for(int i = 0; i < 4; ++i) {
            int newRow = row + moves[i][0];
            int newCol = col + moves[i][1];
            if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
            if(vis[parity][newRow][newCol]) continue;
            q[parity].push({max(effort, abs(heights[newRow][newCol] - heights[row][col])), newRow * cols + newCol});
          }
          break;
        }
      }
    }
    return -1;
  }
};

// Accepted
// 75/75 cases passed (36 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.52 % of cpp submissions (16.8 MB)
// @lc code=end

