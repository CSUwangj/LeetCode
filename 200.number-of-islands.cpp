/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
  int move[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
  int height;
  int width;
  vector<vector<bool>> visited;
  void dfs(vector<vector<char>>& grid, int h, int w) {
    grid[h][w] = '0';
    for(int i = 0; i < 4; ++i) {
      int newH = h + move[i][0];
      int newW = w + move[i][1];
      if(newH >= 0 && newH < height && newW >= 0 && newW < width &&
         grid[newH][newW] == '1') {
        dfs(grid, newH, newW);
      }
    }
  }
public:
  int numIslands(vector<vector<char>>& grid) {
    height = grid.size();
    width = grid[0].size();
    int ans = 0;
    for(int i = 0; i < height; ++i) {
      for(int j = 0; j < width; ++j) {
        if(grid[i][j] == '1') {
          ans += 1;
          dfs(grid, i, j);
        }
      }
    }
    return ans;
  }
};

// Accepted
// 49/49 cases passed (66 ms)
// Your runtime beats 35.13 % of cpp submissions
// Your memory usage beats 97.03 % of cpp submissions (12.2 MB)
// @lc code=end

