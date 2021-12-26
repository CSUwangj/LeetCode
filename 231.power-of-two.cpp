/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
  bool isPowerOfTwo(int n) {
    return n > 0 && !(n & (n - 1));
  }
};

// Accepted
// 1108/1108 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.12 % of cpp submissions (5.9 MB)
// @lc code=end
