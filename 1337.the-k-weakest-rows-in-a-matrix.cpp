/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
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
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int rows = mat.size();
    int cols = mat.front().size();
    vector<int> rowCount(rows);
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        rowCount[i] += mat[i][j];
        if(!mat[i][j]) break;
      }
    }
    vector<int> answer(rows);
    for(int i = 0; i < rows; ++i) {
      answer[i] = i;
    }
    sort(answer.begin(), answer.end(), [&](int a, int b) {
      return rowCount[a] < rowCount[b] || (rowCount[a] == rowCount[b] && a < b);
    });
    answer.resize(k);
    return move(answer);
  }
};

// Accepted
// 52/52 cases passed (11 ms)
// Your runtime beats 41.87 % of cpp submissions
// Your memory usage beats 9.15 % of cpp submissions (10.8 MB)
// @lc code=end
