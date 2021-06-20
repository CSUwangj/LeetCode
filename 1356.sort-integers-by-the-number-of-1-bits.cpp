/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

// @lc code=start
const int M1  = 0X55555555; // 01010101010101010101010101010101
const int M2  = 0X33333333; // 00110011001100110011001100110011
const int M4  = 0X0F0F0F0F; // 00001111000011110000111100001111
const int M8  = 0X00FF00FF; // 00000000111111110000000011111111
const int M16 = 0X0000FFFF; // 00000000000000001111111111111111
constexpr int popcount(int x) { 
  x = (x & M1) + ((x >> 1) & M1);
  x = (x & M2) + ((x >> 2) & M2);
  x = (x & M4) + ((x >> 4) & M4);
  x = (x & M8) + ((x >> 8) & M8);
  x = (x & M16) + ((x >> 16) & M16);
  return x;
}
class Solution {
public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
      int ba = popcount(a);
      int bb = popcount(b);
      return ba < bb || (ba == bb && a < b); 
    });
    return arr;
  }
};
// @lc code=end

