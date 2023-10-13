/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
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
  int equalPairs(vector<vector<int>>& grid) {
    map<string, int> rows;
    map<string, int> cols;
    int n = grid.size();
    for(int i = 0; i < n; ++i) {
      string row;
      string col;
      for(int j = 0; j < n; ++j) {
        row.push_back('-');
        col.push_back('-');
        row += to_string(grid[i][j]);
        col += to_string(grid[j][i]);
      }
      rows[row] += 1;
      cols[col] += 1;
    }
    int answer = 0;
    for(const auto &[s, c] : rows) {
      answer += cols[s] * c;
    }

    return answer;
  }
};

// Accepted
// 72/72 cases passed (227 ms)
// Your runtime beats 42.93 % of cpp submissions
// Your memory usage beats 13.65 % of cpp submissions (45.7 MB)
// @lc code=end

