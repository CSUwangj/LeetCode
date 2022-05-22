/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
  int move[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid.front().front() || grid.back().back()) return -1;
    int n = grid.size();
    vector<vector<int>> dis(n, vector<int>(n));
    dis[0][0] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while(!q.empty()) {
      auto [row, col] = q.front();
      q.pop();
      for(int i = 0; i < 8; ++i) {
        int newRow = row + move[i][0];
        int newCol = col + move[i][1];
        if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || grid[newRow][newCol]) continue;
        if(dis[newRow][newCol]) continue;
        dis[newRow][newCol] = dis[row][col] + 1;
        q.push(make_pair(newRow, newCol));
      }
    }
    return dis.back().back() ? dis.back().back() : -1;
  }
};

// Accepted
// 88/88 cases passed (82 ms)
// Your runtime beats 65.2 % of cpp submissions
// Your memory usage beats 49.22 % of cpp submissions (20.8 MB)
// @lc code=end

