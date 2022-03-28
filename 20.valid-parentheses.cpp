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
// 91/91 cases passed (5 ms)
// Your runtime beats 18.36 % of cpp submissions
// Your memory usage beats 51.5 % of cpp submissions (6.3 MB)
// @lc code=end
