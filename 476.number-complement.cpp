/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
  int findComplement(int n) {
    if(n > INT_MAX / 2) return INT_MAX ^ n;
    int bit = 1;
    while(bit <= n) {
      bit <<= 1;
    }
    return (bit - 1 | 1) ^ n;
  }
};

// Accepted
// 149/149 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 40.00 % of cpp submissions (6 MB)
// @lc code=end
