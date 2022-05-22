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
bool vis[100][100];
class Solution {
  int rows;
  int cols;
  int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  bool verify(vector<vector<int>>& heights, int effort) {
    memset(vis, 0, sizeof(vis));
    queue<pi> q;
    q.push({0, 0});
    vis[0][0] = true;
    while(q.size()) {
      auto [row, col] = q.front();
      q.pop();
      if(row == rows - 1 && col == cols - 1) return true;
      for(int i = 0; i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(vis[newRow][newCol]) continue;
        if(abs(heights[newRow][newCol] - heights[row][col]) > effort) continue;
        vis[newRow][newCol] = true;
        q.push({newRow, newCol});
      }
    }
    return false;
  }
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    rows = heights.size();
    cols = heights.front().size();
    int mmin = INT_MAX;
    int mmax = INT_MIN;
    for(auto &row :heights) {
      mmin = min(mmin, *min_element(row.begin(), row.end()));
      mmax = max(mmax, *max_element(row.begin(), row.end()));
    }
    int low = 0;
    int high = mmax - mmin;
    while(low < high) {
      int mid = (low + high) >> 1;
      if(!verify(heights, mid)) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};

// Accepted
// 75/75 cases passed (294 ms)
// Your runtime beats 56.19 % of cpp submissions
// Your memory usage beats 43.06 % of cpp submissions (39.2 MB)
// @lc code=end

