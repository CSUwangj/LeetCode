/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
bool isOp(string &token) {
  return token.length() == 1 && !isdigit(token[0]);
}

int apply(string &op, int op1, int op2) {
  switch (op[0]) {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
  }
  return -1;
}

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    vector<int> st;
    for(auto &token : tokens) {
      if(isOp(token)) {
        int op2 = st.back();
        st.pop_back();
        int op1 = st.back();
        st.pop_back();
        st.push_back(apply(token, op1, op2));
      } else {
        st.push_back(stoi(token));
      }
    }
    return st.back();
  }
};
// @lc code=end

