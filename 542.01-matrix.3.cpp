/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
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
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    for(auto &row : mat) {
      for(auto &i : row) if(i) i = 10000;
    }
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(!mat[i][j]) continue;
        if(i) mat[i][j] = min(mat[i][j], mat[i - 1][j] + 1);
        if(j) mat[i][j] = min(mat[i][j], mat[i][j - 1] + 1);
      }
    }
    for(int i = rows - 1; i >= 0; --i) {
      for(int j = cols - 1; j >= 0; --j) {
        if(!mat[i][j]) continue;
        if(i != rows - 1) mat[i][j] = min(mat[i][j], mat[i + 1][j] + 1);
        if(j != cols - 1) mat[i][j] = min(mat[i][j], mat[i][j + 1] + 1);
      }
    }
    return mat;
  }
};

// Accepted
// 49/49 cases passed (56 ms)
// Your runtime beats 95.88 % of cpp submissions
// Your memory usage beats 96.98 % of cpp submissions (26.1 MB)
// @lc code=end

