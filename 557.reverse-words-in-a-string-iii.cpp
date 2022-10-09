/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
  string reverseWords(string s) {
    bool isSpace = true;
    int start = -1;
    for (int i = 0; i < s.length(); ++i) {
      if(isSpace && s[i] != ' ') {
        start = i;
      } else if(!isSpace && s[i] == ' ') {
        reverse(s.begin() + start, s.begin() + i);
      }
      isSpace = s[i] == ' ';
    }
    if(!isSpace) reverse(s.begin() + start, s.end());
    return s;
  }
};

// Accepted
// 29/29 cases passed (48 ms)
// Your runtime beats 16.64 % of cpp submissions
// Your memory usage beats 45.42 % of cpp submissions (9.7 MB)
// @lc code=end
