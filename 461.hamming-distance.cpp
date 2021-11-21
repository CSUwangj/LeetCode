/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
const int M1  = 0x55555555; // 01010101
const int M2  = 0x33333333; // 00110011
const int M4  = 0x0F0F0F0F; // 00001111
const int M8  = 0x00FF00FF; 
const int M16 = 0x0000FFFF;
constexpr int pop_count(int x) {
  x = (x & M1) + ((x >> 1) & M1);
  x = (x & M2) + ((x >> 2) & M2);
  x = (x & M4) + ((x >> 4) & M4);
  x = (x & M8) + ((x >> 8) & M8);
  x = (x & M16) + ((x >> 16) & M16);
  return x;
}
class Solution {
public:
  int hammingDistance(int x, int y) {
    return pop_count(x ^ y);
  }
};

// Accepted
// 149/149 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.54 % of cpp submissions (5.9 MB)
// @lc code=end
