/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
unordered_map<string, int> cache;
unordered_map<string, bool> palinCache;
class Solution {
  bool isPalindrome(string s, int len) {
    if(palinCache.count(s)) return palinCache[s];
    for(int i = 0; i * 2 < len; ++i) {
      if(s[i] != s[len - 1 - i]) return palinCache[s] = false;
    }

    return palinCache[s] = true;
  }
public:
  int minCut(string s) {
    if(cache.count(s)) return cache[s];
    int len = s.length();
    if(isPalindrome(s, len)) return 0;
    int answer = len - 1;
    for(int i = 1; i < len; ++i) {
      answer = min(answer, minCut(s.substr(0, i)) + minCut(s.substr(i)) + 1);
    }
    return cache[s] = answer;
  }
};
// @lc code=end

