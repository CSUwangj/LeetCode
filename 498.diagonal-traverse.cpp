/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */

// @lc code=start
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    int row = 0;
    int col = 0;
    int direction = 1;
    vector<int> answer;
    while(row < rows && col < cols) {
      // cout << row << ' ' <<col << " -> ";
      answer.push_back(mat[row][col]);
      row -= direction;
      col += direction;
      // cout << row << ' ' <<col << endl;
      direction = -direction;
      if(col == cols) {
        row += 2;
        col -= 1;
      } else if(row == rows) {
        col += 2;
        row -= 1;
      } else if(row < 0) {
        row = 0;
      } else if(col < 0) {
        col = 0;
      } else {
        direction = -direction;
      }
    }
    return answer;
  }
};
// @lc code=end

