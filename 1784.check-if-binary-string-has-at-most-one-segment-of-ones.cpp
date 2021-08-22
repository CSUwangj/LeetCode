/*
 * @lc app=leetcode id=1784 lang=cpp
 *
 * [1784] Check if Binary String Has at Most One Segment of Ones
 */

// @lc code=start
class Solution {
public:
  bool checkOnesSegment(string s) {
    int change = 0;
    int prev = '0';
    for(auto c : s) {
      change += (c != prev);
      prev = c;
    }
    return change < 3;
  }
};

// Accepted
// 191/191 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 92.06 % of cpp submissions (5.9 MB)
// @lc code=end

