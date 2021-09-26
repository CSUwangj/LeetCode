/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 */

// @lc code=start
class Solution {
public:
  string breakPalindrome(string palindrome) {
    int len = palindrome.length();
    if(len == 1) return "";
    for(int i = 0; i * 2 + 1 < len; ++i) {
      if(palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;
      }
    }
    palindrome.back() = 'b';
    return palindrome;
  }
};

// Accepted
// 30/30 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 45.58 % of cpp submissions (6.2 MB)
// @lc code=end

