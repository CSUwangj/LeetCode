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
public:
  bool validPalindrome(string s) {
    int len = s.length();
    bool skiped = false;
    bool ok = true;
    for(int i = 0; i * 2 < len; ++i) {
      if(s[i + skiped] == s[len - 1 - i]) continue;
      if(!skiped && s[i + 1] == s[len - 1 - i]) {
        skiped = true;
        continue;
      }
      ok = false;
      break;
    }
    if(ok) return true;
    skiped = false;
    ok = true;
    for(int i = 0; i * 2 < len; ++i) {
      if(s[i] == s[len - 1 - i - skiped]) continue;
      if(!skiped && s[i] == s[len - 2 - i]) {
        skiped = true;
        continue;
      }
      ok = false;
      break;
    }
    return ok;
  }
};

// Accepted
// 467/467 cases passed (40 ms)
// Your runtime beats 99.53 % of cpp submissions
// Your memory usage beats 56.51 % of cpp submissions (19.7 MB)
// @lc code=end
