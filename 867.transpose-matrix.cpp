/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
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
  vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    vector<vector<int>> answer;
    for(int i = 0; i < cols; ++i) {
      vector<int> row(rows);
      for(int j = 0; j < rows; ++j) {
        row[j] = matrix[j][i];
      }
      answer.emplace_back(row);
    }
    return move(answer);
  }
};

// Accepted
// 36/36 cases passed (7 ms)
// Your runtime beats 97.84 % of cpp submissions
// Your memory usage beats 13.79 % of cpp submissions (10.8 MB)
// @lc code=end

