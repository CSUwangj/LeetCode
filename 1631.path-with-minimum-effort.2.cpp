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
class Solution {
  int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
      typedef pair<int, int> pi;
      int rows = heights.size();
      int cols = heights.front().size();
      vector<vector<bool>> vis(rows, vector<bool>(cols));
      auto cmp = [](pair<int, pi> &left, pair<int, pi> &right) { return left.first > right.first; };
      priority_queue<pair<int, pi>, vector<pair<int, pi>>, decltype(cmp)> q(cmp);
      q.push(make_pair(0, make_pair(0, 0)));
      while(!q.empty()) {
        auto [effort, pos] = q.top();
        q.pop();
        auto [row, col] = pos;
        // cout << effort << ' ' << row << ' ' << col << endl;
        if(vis[row][col]) continue;
        vis[row][col] = true;
        if(row == rows - 1 && col == cols - 1) return effort;
        for(int i = 0; i < 4; ++i) {
          int newRow = row + moves[i][0];
          int newCol = col + moves[i][1];
          if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols || vis[newRow][newCol]) continue;
          q.push(make_pair(max(effort, abs(heights[row][col]-heights[newRow][newCol])), make_pair(newRow, newCol)));
        }
    }
    return -1;
  }
};
// @lc code=end

