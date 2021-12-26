/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
  bool shouldCompute(char current, char last) {
    if(current == '+' || current == '-') return true;
    if(last == '*' || last == '/') return true;
    return false;
  }
  void compute(stack<int> &n, stack<char> &op) {
    int op2 = n.top();
    n.pop();
    int op1 = n.top();
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
public:
  int calculate(string s) {
    int curNum = 0;
    bool inNum = false;
    stack<int> n;
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
};

// Accepted
// 109/109 cases passed (16 ms)
// Your runtime beats 26.58 % of cpp submissions
// Your memory usage beats 71.03 % of cpp submissions (7.9 MB)
// @lc code=end

