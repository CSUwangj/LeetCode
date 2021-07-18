/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
  int titleToNumber(string columnTitle) {
    int result = 0;
    for(auto c : columnTitle) {
      result *= 26;
      result += c - 'A' + 1;
    }
  }
};
// @lc code=end

