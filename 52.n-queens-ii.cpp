/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
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
  int answer = 0;

  void solve(int cur, int n) {
    if(cur == n) {
      answer += 1;
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
  int totalNQueens(int n) {
    solve(0, n);
    return answer;
  }
};

// Accepted
// 9/9 cases passed (6 ms)
// Your runtime beats 64.32 % of cpp submissions
// Your memory usage beats 97.4 % of cpp submissions (5.8 MB)
// @lc code=end

