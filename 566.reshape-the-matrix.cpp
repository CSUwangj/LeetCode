/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    if(r * c != mat.size() * mat.front().size()) return mat;
    int cnt = 0;
    vector<int> tmp;
    vector<vector<int>> answer;
    for(auto &row : mat) {
      for(auto num : row) {
        tmp.push_back(num);
        if(++cnt % c == 0) {
          answer.push_back(tmp);
          tmp.clear();
        }
      }
    }
    return answer;
  }
};
// @lc code=end

