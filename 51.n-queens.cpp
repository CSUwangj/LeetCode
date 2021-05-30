/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
int rows[9];
bool check(int row, int col) {
  for(int i = 0; i < row; ++i) {
    if(abs(i - row) == abs(rows[i] - col) || col == rows[i]) return false;
  }
  return true;
}
class Solution {
  vector<vector<string>> answer;

  void addResult(int n) {
    vector<string> result;
    for(int i = 0; i < n; ++i) {
      string row(n, '.');
      row[rows[i]] = 'Q';
      result.emplace_back(row);
    }
    answer.emplace_back(result);
  }

  void solve(int cur, int n) {
    if(cur == n) {
      addResult(n);
      return;
    }
    for(int i = 0; i < n; ++i) {
      if(check(cur, i)) {
        rows[cur] = i;
        solve(cur + 1, n);
      }
    }
  }
public:
  vector<vector<string>> solveNQueens(int n) {
    solve(0, n);
    return move(answer);
  }
};
// @lc code=end

