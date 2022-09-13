/*
 * @lc app=leetcode id=1329 lang=cpp
 *
 * [1329] Sort the Matrix Diagonally
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    for(int i = 0; i < rows+cols-1; ++i) {
      int rowBegin = max(0, i+1-cols);
      int colBegin = rowBegin == 0 ? cols - 1 - i : 0;
      // cout << '#' << rowBegin << ' ' << colBegin << endl;
      for(int index = 0; rowBegin + index < rows-1 && colBegin + index < cols-1; ++index) {
        for(int j = 1; rowBegin + j < rows-index && colBegin + j < cols-index; ++j) {
          // cout << rowBegin + j << ' ' << colBegin + j << endl;
          if(mat[rowBegin+j][colBegin+j] < mat[rowBegin+j-1][colBegin+j-1]) {
            swap(mat[rowBegin+j][colBegin+j], mat[rowBegin+j-1][colBegin+j-1]);
          }
        }
      }
    }
    return move(mat);
  }
};

// Accepted
// 15/15 cases passed (33 ms)
// Your runtime beats 10.63 % of cpp submissions
// Your memory usage beats 99.93 % of cpp submissions (8.4 MB)
// @lc code=end

