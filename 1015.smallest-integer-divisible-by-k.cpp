/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 */

// @lc code=start
class Solution {
public:
  int smallestRepunitDivByK(int k) {
      if(k % 2 == 0 || k % 5 == 0) return -1;
      int cur = 0;
      for(int i = 1; i <= k; ++i) {
          cur = (cur * 10 + 1) % k;
          if(cur == 0) return i;
      }
      // actually won't go to here
      return INT_MAX;
  }
};

// Accepted
// 70/70 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 46.22 % of cpp submissions (6 MB)
// @lc code=end
