/*
 * @lc app=leetcode id=458 lang=cpp
 *
 * [458] Poor Pigs
 */

// @lc code=start
class Solution {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int base = 1 + minutesToTest / minutesToDie;
    return ceil(log(buckets) / log(base));
  }
};

// Accepted
// 17/17 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 58.91 % of cpp submissions (6 MB)
// @lc code=end

