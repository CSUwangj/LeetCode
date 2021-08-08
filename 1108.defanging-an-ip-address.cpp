/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 */

// @lc code=start
class Solution {
public:
  string defangIPaddr(string address) {
    return regex_replace(address, regex("\\."), "[.]");
  }
};

// Accepted
// 62/62 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 21.4 % of cpp submissions (6.8 MB)
// @lc code=end

