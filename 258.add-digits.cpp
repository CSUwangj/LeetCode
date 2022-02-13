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
// 1101/1101 cases passed (5 ms)
// Your runtime beats 17.94 % of cpp submissions
// Your memory usage beats 75.31 % of cpp submissions (5.9 MB)
// @lc code=end
