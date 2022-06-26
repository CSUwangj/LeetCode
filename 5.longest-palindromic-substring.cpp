/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
  string longestPalindrome(string s) {
    int len = s.length();
    int answer = 1;
    int begin = 0;
    for(int i = 0; i < len; ++i) {
      int left = i, right = i;
      while(left > 0 && right < len && s[left-1] == s[right]) {
        left -= 1;
        right += 1;
      }
      if(right - left > answer) {
        answer = right - left;
        begin = left;
      }
      left = i, right = i;
      while(left >= 0 && right < len && s[left] == s[right]) {
        left -= 1;
        right += 1;
      }
      if(right - left - 1 > answer) {
        answer = right - left - 1;
        begin = left + 1;
      }
      
    }
    return s.substr(begin, answer);
  }
};

// Accepted
// 180/180 cases passed (34 ms)
// Your runtime beats 76.7 % of cpp submissions
// Your memory usage beats 81.58 % of cpp submissions (7.2 MB)
// @lc code=end

