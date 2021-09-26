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
  vector<char> ops;
  int len;
  void addExpression(string &num) {
    string result;
    for(int i = 0; i < len; ++i) {
      if(ops[i]) {
        result.push_back(ops[i]);
      }
      result.push_back(num[i]);
    }
    answer.push_back(result);
  }
  void solve(string &num, int target, int start, long value, long last) {
    if(start == len) {
      if(target == value) {
        addExpression(num);
      }
      return;
    }

    long n = 0;
    string nStr;
    for(int i = start; i < len; ++i) {
      n *= 10;
      n += num[i] - '0';
      nStr.push_back(num[i]);

      if(!start) {
        solve(num, target, i + 1, n, n);
      } else {
        ops[start] = '*';
        solve(num, target, i + 1, value - last + n * last, n * last);
        ops[start] = '+';
        solve(num, target, i + 1, value + n, n);
        ops[start] = '-';
        solve(num, target, i + 1, value - n, -n);
      }

      if(n == 0) break;
    }
    ops[start] = 0;
  }
public:
  vector<string> addOperators(string num, int target) {
    len = num.length();
    ops.resize(len);
    solve(num, target, 0, 0, 0);
    return answer;
  }
};

// Accepted
// 20/20 cases passed (42 ms)
// Your runtime beats 94.62 % of cpp submissions
// Your memory usage beats 82.64 % of cpp submissions (16.8 MB)
// @lc code=end

