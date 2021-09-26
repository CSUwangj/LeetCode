/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */

// @lc code=start
const char OP[] = {'+', '-', '*'};
class Solution {
  int target;
  string expr;
  string num;
  bool valid(string &s) {
    int len = s.length();
    for(int i = 0; i < len - 1; ++i) {
      if(s[i] == '0' && isdigit(s[i])) return false;
    }
    return true;
  }

  // copy from my 227
  bool shouldCompute(char current, char last) {
    if(current == '+' || current == '-') return true;
    if(last == '*' || last == '/') return true;
    return false;
  }
  void compute(stack<long long> &n, stack<char> &op) {
    long long op2 = n.top();
    n.pop();
    long long op1 = n.top();
    n.pop();
    int o = op.top();
    op.pop();
    switch(o){
      case '+':
        n.push(op1+op2);
        break;
      case '-':
        n.push(op1-op2);
        break;
      case '*':
        n.push(op1*op2);
        break;
      case '/':
        n.push(op1/op2);
        break;
    }
  }
  int calculate(string &s) {
    long long curNum = 0;
    bool inNum = false;
    stack<long long> n;
    stack<char> op;
    for(auto c : s) {
      if(inNum && !isdigit(c)) {
        n.push(curNum);
        curNum = 0;
        inNum = false;
      }
      if(c == ' ') continue;
      if(isdigit(c)) {
        curNum *= 10;
        curNum += c - '0';
        inNum = true;
      } else {
        while(op.size() && shouldCompute(c, op.top())) {
          compute(n, op);
        }
        op.push(c);
      }
    }
    if(inNum) n.push(curNum);
    while(op.size()) {
      compute(n, op);
    }
    return n.top();
  }
  void solve(vector<string> &answer, int pos) {
    cout <<expr << ' ' << pos << endl;
    if(pos == num.length()) {
      if(valid(expr) && calculate(expr) == target) {
        answer.push_back(expr);
      }
      return;
    }
    expr.push_back(num[pos]);
    solve(answer, pos + 1);
    expr.pop_back();
    for(auto op : OP) {
      expr.push_back(op);
      expr.push_back(num[pos]);
      solve(answer, pos + 1);
      expr.pop_back();
      expr.pop_back();
    }
  }
public:
  vector<string> addOperators(string num, int target) {
    expr.push_back(num[0]);
    this->target = target;
    this->num = num;
    vector<string> answer;
    solve(answer, 1);
    return answer;
  }
};
// @lc code=end

