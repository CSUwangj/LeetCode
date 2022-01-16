/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class KMP {
  vector<int> table{-1};
  string pattern;
  int patternLen;
public:
  KMP(string &pattern): pattern(pattern) {
    patternLen = pattern.length();
    table.resize(patternLen);
    int pos = 1;
    int cnd = 0;
    while(pos < patternLen) {
      if(pattern[pos] == pattern[cnd]) {
        table[pos] = table[cnd];
      } else {
        table[pos] = cnd;
        while(cnd >= 0 && pattern[pos] != pattern[cnd]) {
          cnd = table[cnd];
        }
      }
      pos += 1;
      cnd += 1;
    }
  }

  int search(const string &s) const {
    int posPattern = 0;
    int posStr = 0;
    int len = s.length();
    while(posStr < len) {
      if(s[posStr] == pattern[posPattern]) {
        posStr += 1;
        posPattern += 1;
        if(posPattern == patternLen) return posStr - patternLen;
      } else {
        posPattern = table[posPattern];
        if(posPattern < 0) {
          posPattern += 1;
          posStr += 1;
        }
      }
    }
    return -1;
  }
};

class Solution {
public:
  int strStr(string haystack, string needle) {
    if(needle.empty()) return 0;
    if(needle.length() > haystack.length()) return -1;
    return KMP(needle).search(haystack);
  }
};

// Accepted
// 80/80 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 26.55 % of cpp submissions (7.5 MB)
// @lc code=end
