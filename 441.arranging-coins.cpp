/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
  int arrangeCoins(int n) {
    long long begin = 0, end = n;
    while(begin < end) {
      long long mid = (begin + end) / 2;
      long long need = (mid + 1LL) * mid / 2;
      if(need < n) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    if(begin * (begin + 1) / 2 > n) begin -= 1;
    return begin;
  }
};

// Accepted
// 1335/1335 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 96.1 % of cpp submissions (5.8 MB)
// @lc code=end

