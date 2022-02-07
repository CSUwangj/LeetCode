/*
 * @lc app=leetcode id=1763 lang=cpp
 *
 * [1763] Longest Nice Substring
 */

// @lc code=start
class Solution {
public:
  string longestNiceSubstring(string s) {
    int len = s.length();
    for(int l = len; l >= 2; --l) {
      for(int b = 0; b + l <= len; ++b) {
        bool appear[52] = {};
        for(int i = b; i < b + l; ++i) {
          if(isupper(s[i])) {
            appear[(s[i] - 'A') * 2 + 1] = true;
          } else {
            appear[(s[i] - 'a') * 2] = true;
          }
        }
        bool ok = true;
        for(int i = 0; i < 52 && ok; i += 2) {
          if(appear[i] != appear[i + 1]) ok = false;
        }
        if(ok) return s.substr(b, l);
      }
    }
    return "";
  }
};

// Accepted
// 73/73 cases passed (16 ms)
// Your runtime beats 59.91 % of cpp submissions
// Your memory usage beats 97.08 % of cpp submissions (6.1 MB)
// @lc code=end
