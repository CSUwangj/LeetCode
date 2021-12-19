/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
  string decodeString(string s) {
    stack<pair<string, int>> st;
    string current;
    int repeat = 0;
    for(auto c : s) {
      if(islower(c)) {
        current += c;
      } else if (isdigit(c)) {
        repeat *= 10;
        repeat += c - '0';
      } else if (c == '[') {
        st.push(make_pair(current, repeat));
        repeat = 0;
        current = "";
      } else {
        auto [lastString, lastRepeat] = st.top();
        st.pop();
        for(int i = 0; i < lastRepeat; ++i) {
          lastString += current;
        }
        current = lastString;
      }
    }
    return current;
  }
};

// Accepted
// 34/34 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 31.99 % of cpp submissions (6.7 MB)
// @lc code=end
