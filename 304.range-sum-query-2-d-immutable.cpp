/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
  vector<vector<int>> sum;
public:
  NumMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    sum.resize(rows + 1, vector<int>(cols + 1));
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
      }
    }
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
  }
};

// Accepted
// 24/24 cases passed (898 ms)
// Your runtime beats 10.43 % of cpp submissions
// Your memory usage beats 79.01 % of cpp submissions (147.9 MB)
// @lc code=end

