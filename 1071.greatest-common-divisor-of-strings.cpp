/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution {
public:
  string gcdOfStrings(string str1, string str2) {
    if(str1.length() < str2.length()) {
      swap(str1, str2);
    }

    int pos1 = 0;
    int pos2 = 0;
    int len1 = str1.length();
    int len2 = str2.length();
    while(pos1 < len1) {
      if(str1[pos1] != str2[pos2]) return "";
      pos1 += 1;
      pos2 = (pos2 + 1) % len2;
    }
    if(pos2 == 0) return str2;
    return gcdOfStrings(str2, str2.substr(pos2));
  }
};

// Accepted
// 114/114 cases passed (3 ms)
// Your runtime beats 83.39 % of cpp submissions
// Your memory usage beats 78.21 % of cpp submissions (7.1 MB)
// @lc code=end

