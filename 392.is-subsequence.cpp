/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
  bool isSubsequence(string s, string t) {
    int sLen = s.length();
    int tLen = t.length();
    if(sLen > tLen) return false;
    int sPos = 0;
    int tPos = 0;
    while(sPos < sLen && tPos < tLen) {
      if(s[sPos] == t[tPos]) {
        sPos += 1;
      }
      tPos += 1;
    }
    return sPos == sLen;
  }
};

// Accepted
// 17/17 cases passed (2 ms)
// Your runtime beats 52.38 % of cpp submissions
// Your memory usage beats 72.95 % of cpp submissions (6.4 MB)
// @lc code=end
