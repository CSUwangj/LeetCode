/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
  int myAtoi(string s) {
    int pos = 0;
    int len = s.length();
    while(pos < len && isspace(s[pos])) pos += 1;
    int cur = 0;
    int sign = 1;
    if(s[pos] == '-') {
      sign = -1;
      pos += 1;
    } else if(s[pos] == '+') {
      sign = 1;
      pos += 1;
    }
    // 2147483648₁₀ & 2147483647₁₀
    while(pos < len && isdigit(s[pos])) {
      if(sign == -1 && (INT_MIN / 10 > cur || (INT_MIN / 10 == cur && s[pos] > '7'))) return INT_MIN;
      if(sign == 1 && (INT_MAX / 10 < cur || (INT_MAX / 10 == cur && s[pos] > '6'))) return INT_MAX;
      cur *= 10;
      cur += sign * (s[pos] - '0');
      pos += 1;
    }
    return cur;
  }
};

// Accepted
// 1082/1082 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 52.29 % of cpp submissions (7 MB)
// @lc code=end
