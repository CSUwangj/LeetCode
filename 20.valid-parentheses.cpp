/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
  bool isValid(string s) {
    vector<char> st;
    for(auto c : s) {
      switch(c) {
        case '(':
        case '[':
        case '{':
          st.push_back(c);
          break;
        case ')':
          if(st.empty() || st.back() != '(') {
            return false;
          }
          st.pop_back();
          break;
        case ']':
          if(st.empty() || st.back() != '[') {
            return false;
          }
          st.pop_back();
          break;
        case '}':
          if(st.empty() || st.back() != '{') {
            return false;
          }
          st.pop_back();
          break;
        default:
          return false;
      }
    }
    return st.empty();
  }
};

// Accepted
// 93/93 cases passed (2 ms)
// Your runtime beats 46.33 % of cpp submissions
// Your memory usage beats 56.25 % of cpp submissions (6.4 MB)
// @lc code=end
