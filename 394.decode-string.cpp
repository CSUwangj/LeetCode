/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
  int len;
  string decode(string &s, int &pos) {
    string result;
    while(pos < len) {
      if(islower(s[pos])) {
        result.push_back(s[pos]);
      } else if(isdigit(s[pos])) {
        int repeat = 0;
        while(isdigit(s[pos])) {
          repeat *= 10;
          repeat += s[pos] - '0';
          pos += 1;
        }
        pos += 1;
        string repeatS = decode(s, pos);
        while(repeat--) {
          result += repeatS;
        }
      } else if(s[pos] == ']') {
        return result;
      }
      pos += 1;
    }
    return result;
  }
public:
  string decodeString(string s) {
    len = s.length();
    int pos = 0;
    return decode(s, pos);
  }
};

// Accepted
// 34/34 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 90.28 % of cpp submissions (6.4 MB)
// @lc code=end
