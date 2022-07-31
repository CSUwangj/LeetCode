/*
 * @lc app=leetcode id=736 lang=cpp
 *
 * [736] Parse Lisp Expression
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  map<string, vector<int>> variables;
  map<int, set<string>> lifetime;
  bool readExpression(const string &input, int &pos, string &ret) {
    if(pos == input.length()) return false;
    if(input[pos] == ')') {
      pos += 1;
      return false;
    }
    while(input[pos] == ' ') pos += 1;
    int len = 1;
    bool complex = false;
    int count = 1;
    if(input[pos] == '(') {
      complex = true;
    }
    while(count) {
      count -= (input[pos + len] == ')' || (!complex && input[pos + len] == ' '));
      count += (complex ? input[pos + len] == '(' : 0);
      len += 1;
    }
    ret = input.substr(pos, len - !complex);
    pos += len;
    return true;
  }
public:
  int evaluate(string expression, int level = 0) {
    if(expression.front() != '(') {
      if(expression.front() == '-' || isdigit(expression.front())) {
        return stoi(expression);
      }
      // cout << expression << " has " << variables[expression].size() << endl;
      return variables[expression].back();
    }
    if(expression[1] == 'l') {
      string token1;
      string token2;
      int pos = 5;
      while(true) {
        readExpression(expression, pos, token1);
        if(!readExpression(expression, pos, token2)) {
          break;
        }
        if(lifetime[level].count(token1)) {
          // cout << expression << " replaced " << token1 << endl;
          variables[token1].back() = evaluate(token2, level + 1);
        } else {
          lifetime[level].insert(token1);
          variables[token1].push_back(evaluate(token2, level + 1));
        }
        // cout << "let " << token1 << " = " << token2 << endl;
      }
      int result = evaluate(token1, level + 1);
      for(const auto &variable : lifetime[level]) {
        variables[variable].pop_back();
      }
      lifetime[level].clear();
      // cout << expression << " = " << result << endl;
      return result;
    } else if(expression[1] == 'a') {
      int result = 0;
      int pos = 5;
      string token;
      while(readExpression(expression, pos, token)) {
        result += evaluate(token, level + 1);
      }
      // cout << expression << " = " << result << endl;
      return result;
    } else if(expression[1] == 'm') {
      int result = 1;
      int pos = 6;
      string token;
      while(readExpression(expression, pos, token)) {
        result *= evaluate(token, level + 1);
      }
      // cout << expression << " = " << result << endl;
      return result;
    }
    return -1;
  }
};

// Accepted
// 66/66 cases passed (6 ms)
// Your runtime beats 85.71 % of cpp submissions
// Your memory usage beats 54.55 % of cpp submissions (12.2 MB)
// @lc code=end

