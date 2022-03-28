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
      int low = 0, high = cols - 1;
      while(low < high) {
        int mid = (low + high) >> 1;
        if(mat[i][mid]) {
          low = mid + 1;
        } else {
          high = mid;
        }
      }
      rowCount[i] = mat[i][low] ? low + 1 : low;
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
// 52/52 cases passed (18 ms)
// Your runtime beats 46.89 % of cpp submissions
// Your memory usage beats 19.79 % of cpp submissions (10.7 MB)
// @lc code=end
