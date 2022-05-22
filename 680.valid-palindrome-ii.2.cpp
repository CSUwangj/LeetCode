/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool validPalindrome(const string &s, int left, int right, int del = 1) {
    if(left >= right) return true;
    if(s[left] == s[right]) return validPalindrome(s, left + 1, right - 1, del);
    if(del) return validPalindrome(s, left, right - 1, 0) || validPalindrome(s, left + 1, right, 0);
    return false;
  }
public:
  bool validPalindrome(string s) {
    int len = s.length();
    return validPalindrome(s, 0, len - 1);
  }
};

// Accepted
// 467/467 cases passed (36 ms)
// Your runtime beats 99.67 % of cpp submissions
// Your memory usage beats 87.28 % of cpp submissions (19.5 MB)
// @lc code=end
