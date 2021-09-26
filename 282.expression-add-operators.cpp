/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  vector<string> answer;
  void solve(string &num, int target, int start, string expr, long value, long last) {
    if(start == num.length()) {
      if(target == value) {
        answer.push_back(expr);
      }
      return;
    }

    long n = 0;
    string nStr;
    for(int i = start; i < num.length(); ++i) {
      n *= 10;
      n += num[i] - '0';
      nStr.push_back(num[i]);

      if(!start) {
        solve(num, target, i + 1, nStr, n, n);
      } else {
        solve(num, target, i + 1, expr + "*" + nStr, value - last + n * last, n * last);
        solve(num, target, i + 1, expr + "+" + nStr, value + n, n);
        solve(num, target, i + 1, expr + "-" + nStr, value - n, -n);
      }

      if(n == 0) break;
    }
  }
public:
  vector<string> addOperators(string num, int target) {
    solve(num, target, 0, "", 0, 0);
    return answer;
  }
};

// Accepted
// 20/20 cases passed (415 ms)
// Your runtime beats 49.31 % of cpp submissions
// Your memory usage beats 12.67 % of cpp submissions (95.2 MB)
// @lc code=end

