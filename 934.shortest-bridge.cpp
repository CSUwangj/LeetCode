/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
class Solution {
  const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  using pi = pair<int, int>;
public:
  int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pi> q;
    for(int i = 0; i < n && q.empty(); ++i) {
      for(int j = 0; j < n && q.empty(); ++j) {
        if(grid[i][j]) {
          q.push({i, j});
          grid[i][j] = 2;
        }
      }
    }
    while(q.size()) {
      auto [row, col] = q.front();
      q.pop();
      grid[row][col] = 2;
      for(int m = 0; m < 4; ++m) {
        int newRow = row + moves[m][0];
        int newCol = col + moves[m][1];
        if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) continue;
        if(grid[newRow][newCol] != 1) continue;
        q.push({newRow, newCol});
        grid[newRow][newCol] = 2;
      }
    }

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }

    int answer = 0;
    while(q.size()) {
      int s = q.size();
      for(int _ = 0; _ < s; ++_) {
        auto [row, col] = q.front();
        q.pop();
        for(int m = 0; m < 4; ++m) {
          int newRow = row + moves[m][0];
          int newCol = col + moves[m][1];
          if(newRow < 0 || newCol < 0 || newRow >= n || newCol >= n) continue;
          if(grid[newRow][newCol] == 2) continue;
          if(grid[newRow][newCol] == 1) return answer;
          q.push({newRow, newCol});
          grid[newRow][newCol] = 2;
        }
      }
      answer += 1;
    }
    return -1;
  }
};

// Accepted
// 97/97 cases passed (48 ms)
// Your runtime beats 80.51 % of cpp submissions
// Your memory usage beats 91.3 % of cpp submissions (18.6 MB)
// @lc code=end

