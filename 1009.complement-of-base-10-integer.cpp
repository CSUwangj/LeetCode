/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
  int bitwiseComplement(int n) {
    if(n > INT_MAX / 2) return INT_MAX ^ n;
    int bit = 1;
    while(bit <= n) {
      bit <<= 1;
    }
    return (bit - 1 | 1) ^ n;
  }
};

// Accepted
// 128/128 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 75.27 % of cpp submissions (5.9 MB)
// @lc code=end
