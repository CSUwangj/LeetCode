/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int rows = grid.size();
    int cols = grid.front().size();
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(grid[i][j] == 2) q.push({i, j});
      }
    }

    while(q.size()) {
      auto [row, col] = q.front();
      q.pop();
      for(int m = 0; m < 4; ++m) {
        int newRow = row + moves[m][0];
        int newCol = col + moves[m][1];
        if(newRow < 0 || newRow >= rows || newCol >= cols || newCol < 0) continue;
        if(grid[newRow][newCol] != 1) continue;
        grid[newRow][newCol] = grid[row][col] + 1;
        q.push({newRow, newCol});
      }
    }

    int answer = 2;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(grid[i][j] == 1) return -1;
        answer = max(answer, grid[i][j]);
      }
    }

    return answer - 2;
  }
};

// Accepted
// 306/306 cases passed (4 ms)
// Your runtime beats 92.11 % of cpp submissions
// Your memory usage beats 50.83 % of cpp submissions (13.1 MB)
// @lc code=end

