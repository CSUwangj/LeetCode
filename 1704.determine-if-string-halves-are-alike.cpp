/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

// @lc code=start
constexpr int vowel(char c) {
  switch(c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      return 1;
  }
  return 0;
}
class Solution {
public:
  bool halvesAreAlike(string s) {
    int front = 0;
    int back = 0;
    int len = s.length();
    for(int i = 0; i < len / 2; ++i) {
      front += vowel(s[i]);
    }
    for(int i = len / 2; i < len; ++i) {
      back += vowel(s[i]);
    }
    return front == back;
  }
};

// Accepted
// 113/113 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 56.35 % of cpp submissions (6.6 MB)
// @lc code=end

