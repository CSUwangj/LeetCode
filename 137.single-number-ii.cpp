/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int a = 0;
    int b = 0;
    for(auto n : nums) {
      int tmp = (a&(~b)&(~n)) | ((~b)&(~a)&n);
      b = (b&(~a)&(~n)) | (a&n&(~b));
      a = tmp;
    }
    return a;
  }
};

// Accepted
// 14/14 cases passed (3 ms)
// Your runtime beats 98.52 % of cpp submissions
// Your memory usage beats 72.62 % of cpp submissions (9.4 MB)
// @lc code=end

