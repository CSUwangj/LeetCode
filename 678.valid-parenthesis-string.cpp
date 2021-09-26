/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
class Solution {
public:
  bool checkValidString(string s) {
    int low = 0;
    int high = 0;
    for(auto c : s) {
      if(c == '(') {
        low += 1;
        high += 1;
      } else if(c == ')') {
        low -= 1;
        high -= 1;
      } else {
        low -= 1;
        high += 1;
      }
      if(high < 0) return false;
      if(low < 0) {
        low = 0;
      }
    }
    return low == 0;
  }
};
// @lc code=end

