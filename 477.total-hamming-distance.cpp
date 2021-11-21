/*
 * @lc app=leetcode id=477 lang=cpp
 *
 * [477] Total Hamming Distance
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
  int totalHammingDistance(vector<int>& nums) {
    int len = nums.size();
    int answer = 0;
    for(int i = 0; i < 30; ++i) {
      int bit = (1 << i);
      int count = 0;
      for(auto n : nums) {
        count += !(n & bit);
      }
      answer += (len - count) * count;
    }
    return answer;
  }
};
// @lc code=end
