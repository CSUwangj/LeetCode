/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
const uint32_t m1 = 0x55555555;
const uint32_t m2 = 0x33333333;
const uint32_t m4 = 0x0F0F0F0F;
const uint32_t m8 = 0x00FF00FF;
const uint32_t m16 = 0x0000FFFF;
class Solution { 
public:
  int hammingWeight(uint32_t n) {
    n = (n & m1) + ((n >> 1) & m1);
    n = (n & m2) + ((n >> 2) & m2);
    n = (n & m4) + ((n >> 4) & m4);
    n = (n & m8) + ((n >> 8) & m8);
    n = (n & m16) + ((n >> 16) & m16);
    return n;
  }
};

// Accepted
// 601/601 cases passed (7 ms)
// Your runtime beats 12.48 % of cpp submissions
// Your memory usage beats 48.74 % of cpp submissions (6 MB)
// @lc code=end

