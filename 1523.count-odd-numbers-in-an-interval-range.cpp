/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

// @lc code=start
class Solution {
public:
  int countOdds(int low, int high) {
    return (high - low) / 2 + ((low | high) & 1);
  }
};

// Accepted
// 84/84 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 7.66 % of cpp submissions (6 MB)
// @lc code=end

