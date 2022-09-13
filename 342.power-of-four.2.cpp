/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
  bool isPowerOfFour(int n) {
    return n && __builtin_popcount(n) == 1 && !(__builtin_ctz(n) & 1);
  }
};

// Accepted
// 1061/1061 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 71.3 % of cpp submissions (5.8 MB)
// @lc code=end

