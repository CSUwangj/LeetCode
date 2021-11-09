/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int lowbit = 0;
    for(auto n : nums) lowbit ^= n;
    
    if(lowbit == INT_MIN) lowbit = 1;
    else lowbit &= -lowbit;
    vector<int> answer{0, 0};
    for(auto n : nums) {
      if(n & lowbit) {
        answer[0] ^= n;
      } else {
        answer[1] ^= n;
      }
    }
    return answer;
  }
};

// Accepted
// 32/32 cases passed (8 ms)
// Your runtime beats 85.25 % of cpp submissions
// Your memory usage beats 42.4 % of cpp submissions (10.1 MB)
// @lc code=end

