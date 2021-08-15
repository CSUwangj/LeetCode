/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
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
  void setZeroes(vector<vector<int>>& matrix) {
    bool firstRow = false;
    bool firstCol = false;
    int rows = matrix.size();
    int cols = matrix.front().size();
    for(int i = 0; i < rows; ++i) {
      if(!matrix[i][0]) firstCol = true;
    }
    for(int i = 0; i < cols; ++i) {
      if(!matrix[0][i]) firstRow = true;
    }
    for(int i = 1; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(!matrix[i][j]) {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }
    for(int i = 1; i < rows; ++i) {
      if(!matrix[i][0]) {
        for(int j = 1; j < cols; ++j) {
          matrix[i][j] = 0;
        }
      }
    }
    for(int i = 1; i < cols; ++i) {
      if(!matrix[0][i]) {
        for(int j = 1; j < rows; ++j) {
          matrix[j][i] = 0;
        }
      }
    }
    if(firstCol) {
      for(int j = 0; j < rows; ++j) {
        matrix[j][0] = 0;
      }
    }
    if(firstRow) {
      for(int j = 0; j < cols; ++j) {
        matrix[0][j] = 0;
      }
    }
  }
};

// Accepted
// 164/164 cases passed (11 ms)
// Your runtime beats 82.11 % of cpp submissions
// Your memory usage beats 95.73 % of cpp submissions (13.1 MB)
// @lc code=end

