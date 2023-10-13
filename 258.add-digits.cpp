/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
  int addDigits(int num) {
    if(!num) return num;
    if(!(num % 9)) return 9;
    return num % 9;
  }
};

// Accepted
// 1101/1101 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 7.98 % of cpp submissions (6 MB)
// @lc code=end
