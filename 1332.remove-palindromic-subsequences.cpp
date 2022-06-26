/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */

// @lc code=start
class Solution {
  bool isPalindrome(string &s) {
    int len = s.length();
    for(int i = 0; i * 2 < len; ++i) {
      if(s[i] != s[len - 1 - i]) return false;
    }
    return true;
  }
public:
  int removePalindromeSub(string s) {
    if(s.length() == 0) return 0;
    if(isPalindrome(s)) return 1;
    return 2;
  }
};

// Accepted
// 48/48 cases passed (4 ms)
// Your runtime beats 30.61 % of cpp submissions
// Your memory usage beats 97.7 % of cpp submissions (6.1 MB)
// @lc code=end

