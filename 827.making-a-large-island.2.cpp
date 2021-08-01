/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int n;
  vector<int> lands;
  vector<vector<int>> part;
  vector<vector<bool>> vis;
  void travelIsland(
    vector<vector<int>> &grid,
    int row,
    int col,
    int id
  ) {
    vis[row][col] = true;
    lands[id] += 1;
    part[row][col] = id;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) continue;
      if(vis[newRow][newCol]) continue;
      if(!grid[newRow][newCol]) continue;
      travelIsland(grid, newRow, newCol, id);
    }
  }
public:
  int largestIsland(vector<vector<int>>& grid) {
    n = grid.size();
    part.resize(n, vector<int>(n, -1));
    vis.resize(n, vector<bool>(n));
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(!vis[i][j] && grid[i][j]) {
          lands.push_back(0);
          travelIsland(grid, i, j, cnt);
          cnt += 1;
        }
      }
    }
    if(!lands.size()) return 1;
    if(lands.size() == 1) return min(n * n, lands[0] + 1);

    int answer = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(grid[i][j]) continue;
        unordered_set<int> neighbors;
        int result = 1;
        for(int k = 0; k < 4; ++k) {
          int newRow = i + moves[k][0];
          int newCol = j + moves[k][1];
          if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) continue;
          if(!grid[newRow][newCol]) continue;
          if(neighbors.count(part[newRow][newCol])) continue;
          result += lands[part[newRow][newCol]];
          neighbors.insert(part[newRow][newCol]);
        }
        answer = max(answer, result);
      }
    }

    return answer;
  }
};

// Accepted
// 75/75 cases passed (464 ms)
// Your runtime beats 84.26 % of cpp submissions
// Your memory usage beats 65.91 % of cpp submissions (151.4 MB)
// @lc code=end

