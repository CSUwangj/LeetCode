/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool shouldCompute(char current, char last) {
    if(current == '(') return false;
    if((current == '+' || current == '-') && last != '(') return true;
    if(last == '*' || last == '/') return true;
    return false;
  }
  void compute(stack<int> &n, stack<char> &op) {
    char o = op.top();
    op.pop();
    int op2 = n.top();
    n.pop();
    if(o == 'u') {
      n.push(-op2);
      return;
    }
    int op1 = n.top();
    n.pop();
    // cout << op1 << ' '<< o << " " << op2 << endl;
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
    stack<int> n;
    stack<char> op;
    bool inNum = false;
    bool inCompute = false;
    bool negative = false;
    // cout << "$$$$$$$$$$$$$$$$$$$$" << endl;
    for(auto c : s) {
      if(c == ' ') continue;
      if(inNum && !isdigit(c)) {
        if(negative) curNum = -curNum;
        // cout << curNum << endl;
        n.push(curNum);
        curNum = 0;
        inNum = false;
        negative = false;
      }
      if(!inCompute && !inNum && c == '-') {
        op.push('u');
      } else if(isdigit(c)) {
        curNum *= 10;
        curNum += c - '0';
        inNum = true;
      } else if(c == ')') {
        while(op.size() && op.top() != '(') {
          compute(n, op);
        }
        op.pop();
      } else {
        while(op.size() && shouldCompute(c, op.top())) {
          compute(n, op);
        }
        op.push(c);
      }
      inCompute = c != '(';
    }
    if(inNum) n.push(curNum);
    while(op.size()) {
      compute(n, op);
    }
    return n.top();
  }
};

// Accepted
// 39/39 cases passed (18 ms)
// Your runtime beats 34.2 % of cpp submissions
// Your memory usage beats 28.48 % of cpp submissions (9.4 MB)
// @lc code=end

