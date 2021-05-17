/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
class Solution {
  int len;
  void checkSign(string &s, int &pos) {
    if(s[pos] == '+' || s[pos] == '-')
    pos += 1;
  }

  bool checkInteger(string &s, int &pos) {
    int initPos = pos;
    checkSign(s, pos);
    if(pos < len && isdigit(s[pos])) {
      while(pos < len && isdigit(s[pos])) pos += 1;
      return true;
    } else {
      pos = initPos;
      return false;
    }
  }

  bool checkDecimal(string &s, int &pos) {
    int initPos = pos;
    bool ok = true;
    checkSign(s, pos);
    bool hasFirst = false;
    if(pos < len && isdigit(s[pos])) {
      hasFirst = true;
      while(pos < len && isdigit(s[pos])) pos += 1;
    }
    if(pos < len && s[pos] == '.') {
      pos += 1;
    } else {
      pos = initPos;
      return false;
    }
    if(pos < len && isdigit(s[pos])) {
      while(pos < len && isdigit(s[pos])) pos += 1;
    } else if(!hasFirst) {
      pos = initPos;
      return false;
    }
    return true;
  }  
public:
  bool isNumber(string s) {
    int pos = 0;
    len = s.length();
    if(!(checkDecimal(s, pos) || checkInteger(s, pos))) {
      return false;
    }
    if(pos < len) {
      if(s[pos] != 'e' && s[pos] != 'E') return false;
      pos += 1;
      if(!checkInteger(s, pos)) {
        return false;
      }
    }
    return pos == len;
  }
};
// @lc code=end

