/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    for(int i = 0; i < cols - 1; ++i) {
      int element = matrix[0][i];
      for(int j = 1; j + i < cols && j < rows; ++j) {
        if(matrix[j][i + j] != element) return false;
      }
    }
    for(int i = 1; i < rows - 1; ++i) {
      int element = matrix[i][0];
      for(int j = 1; i + j < rows && j < cols; ++j) {
        if(matrix[i + j][j] != element) return false;
      }
    }
    return true;
  }
};

// Accepted
// 483/483 cases passed (17 ms)
// Your runtime beats 88.89 % of cpp submissions
// Your memory usage beats 15.16 % of cpp submissions (17.5 MB)
// @lc code=end

