/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    int row = 0;
    int col = cols - 1;
    while(row < rows && col >= 0) {
      if(matrix[row][col] == target) return true;
      if(matrix[row][col] > target) {
        col -= 1;
      } else {
        row += 1;
      }
    }
    return false;
  }
};

// Accepted
// 129/129 cases passed (184 ms)
// Your runtime beats 45.36 % of cpp submissions
// Your memory usage beats 21.86 % of cpp submissions (15 MB)
// @lc code=end

