/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
const regex re("^[-+]?((\\d+\\.\\d*)|(\\.\\d+)|\\d+)([eE][+-]?\\d+)?$");
class Solution {
public:
  bool isNumber(string s) {
    return regex_search(s, re);
  }
};
// @lc code=end

