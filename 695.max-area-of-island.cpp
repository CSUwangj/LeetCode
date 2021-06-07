/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int current;
  int rows;
  int cols;
  void dfs(vector<vector<int>>& grid, int row, int col) {
    grid[row][col] = 0;
    current += 1;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
      if(grid[newRow][newCol]) {
        dfs(grid, newRow, newCol);
      }
    }
  }
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    rows = grid.size();
    cols = grid.front().size();
    int answer = 0;
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
        if(grid[i][j]) {
          current = 0;
          dfs(grid, i, j);
          answer = max(answer, current);
        }
      }
    }
    return answer;
  }
};
// @lc code=end

