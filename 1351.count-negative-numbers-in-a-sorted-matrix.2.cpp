/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
  int countNegatives(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();
    int row = rows;
    int col = 0;
    int answer = 0;
    while(row-- && col < cols) {
      while(col < cols && grid[row][col] >= 0) {
        col += 1;
      }
      answer += cols - col;
    }
    return answer;
  }
};
// @lc code=end

