/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution {
public:
  bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
  }
};

// Accepted
// 21038/21038 cases passed (18 ms)
// Your runtime beats 92.54 % of cpp submissions
// Your memory usage beats 88.51 % of cpp submissions (5.8 MB)
// @lc code=end

