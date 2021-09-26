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
  string num;
  int len;
  void addExpression() {
    string result;
    for(int i = 0; i < len; ++i) {
      if(ops[i]) {
        result.push_back(ops[i]);
      }
      result.push_back(num[i]);
    }
    answer.push_back(result);
  }
  void addSymbol(char symbol, int index, long rest, long op1, long op2) {
    ops[index] = symbol;
    index += 1;
    if(index != len) {
      const auto digit = num[index] - '0';
      addSymbol('+', index, rest + op1 * op2, 1, digit);
      addSymbol('-', index, rest + op1 * op2, -1, digit);
      addSymbol('*', index, rest, op1 * op2, digit);
      if(op2) {
        addSymbol(0, index, rest, op1, 10 * op2 + digit);
      }
    } else if(rest + op1 * op2 == 0) {
      addExpression();
    }
  }
public:
  vector<string> addOperators(string num, long target) {
    ops.resize(num.length());
    this->num = num;
    len = num.length();
    addSymbol(0, 0, -target, 1, num[0] - '0');
    return answer;
  }
};

// Accepted
// 20/20 cases passed (15 ms)
// Your runtime beats 99.57 % of cpp submissions
// Your memory usage beats 83.33 % of cpp submissions (16.6 MB)
// @lc code=end

