/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start
class Solution {
public:
  int minPartitions(string n) {
    return *max_element(n.begin(), n.end()) - '0';
  }
};

// Accepted
// 97/97 cases passed (64 ms)
// Your runtime beats 14.51 % of cpp submissions
// Your memory usage beats 92.75 % of cpp submissions (13.4 MB)
// @lc code=end

