/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
  int rows;
  int cols;
  void dfs(vector<vector<int>>& heights, vector<vector<bool>>& vis, int row, int col) {
    if(vis[row][col]) return;
    vis[row][col] = true;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow >= rows || newRow < 0 || newCol >= cols || newCol < 0) continue;
      if(heights[row][col] > heights[newRow][newCol]) continue;
      dfs(heights, vis, newRow, newCol);
    }
  }
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> answer;
    if(heights.empty() || heights.front().empty()) return answer;
    rows = heights.size();
    cols = heights.front().size();
    vector<vector<bool>> visPac(rows, vector<bool>(cols));
    vector<vector<bool>> visAtl(rows, vector<bool>(cols));
    
    for(int i = 0; i < cols; ++i) {
      dfs(heights, visPac, 0, i);
      dfs(heights, visAtl, rows - 1, i);
    }
    for(int i = 0; i < rows; ++i) {
      dfs(heights, visPac, i, 0);
      dfs(heights, visAtl, i, cols - 1);
    }
    
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(visPac[i][j] && visAtl[i][j]) answer.push_back({i, j});
      }
    }
    
    return answer;
  }
};

// Accepted
// 113/113 cases passed (54 ms)
// Your runtime beats 79.37 % of cpp submissions
// Your memory usage beats 77.12 % of cpp submissions (17.5 MB)
// @lc code=end

