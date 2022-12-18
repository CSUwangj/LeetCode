/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    for(int i = 1; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        int lastSum = INT_MAX;
        for(int k = max(0, j - 1); k < min(cols, j + 2); ++k) {
          lastSum = min(lastSum, matrix[i - 1][k]);
        }
        matrix[i][j] += lastSum;
      }
    }
    return *min_element(matrix.back().begin(), matrix.back().end());
  }
};

// Accepted
// 49/49 cases passed (22 ms)
// Your runtime beats 73.89 % of cpp submissions
// Your memory usage beats 84.29 % of cpp submissions (9.9 MB)
// @lc code=end

