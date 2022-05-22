/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] backspace String Compare
 */

// @lc code=start
class Solution {
  char nextChar(const string &s, int &pos) {
    int backspace = 0;
    while(pos >= 0 && (backspace || s[pos] == '#')) {
      if(s[pos] == '#') {
        backspace += 1;
      } else {
        backspace -= 1;
      }
      pos -= 1;
    }
    if(pos < 0) return -1;
    return s[pos];
  }
public:
  bool backspaceCompare(string s, string t) {
    int sPos = s.length() - 1;
    int tPos = t.length() - 1;
    while(sPos >= 0 || tPos >= 0) {
      char cS = nextChar(s, sPos);
      char cT = nextChar(t, tPos);
      if(cS != cT) return false;
      sPos -= 1;
      tPos -= 1;
    }
    return true;
  }
};

// Accepted
// 114/114 cases passed (4 ms)
// Your runtime beats 27.99 % of cpp submissions
// Your memory usage beats 88.07 % of cpp submissions (6.1 MB)
// @lc code=end
