/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */

// @lc code=start
class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    vector<vector<int>> sum(rows + 1, vector<int>(cols + 1));
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
      }
    }
    int answer = 0;
    for(int i = 0; i < cols; ++i) {
      for(int j = i + 1; j <= cols; ++j) {
        multiset<int> tmp{0};
        for(int row = 1; row <= rows; ++row) {
          int curSum = sum[row][j] - sum[row][i];
          answer += tmp.count(curSum - target);
          tmp.insert(curSum);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 40/40 cases passed (1111 ms)
// Your runtime beats 57.65 % of cpp submissions
// Your memory usage beats 41.05 % of cpp submissions (166 MB)
// @lc code=end

