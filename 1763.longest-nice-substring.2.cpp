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
        int upper = 0;
        int lower = 0;
        for(int i = b; i < b + l; ++i) {
          if(isupper(s[i])) {
            upper |= 1 << (s[i] - 'A');
          } else {
            lower |= 1 << (s[i] - 'a');
          }
        }
        if(upper == lower) return s.substr(b, l);
      }
    }
    return "";
  }
};

// Accepted
// 73/73 cases passed (12 ms)
// Your runtime beats 68.05 % of cpp submissions
// Your memory usage beats 92.17 % of cpp submissions (6.2 MB)
// @lc code=end
