/*
 * @lc app=leetcode id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 */

// @lc code=start
long long dp[31] = {0, 1, 3, 8, 19, 43, 94, 201, 423, 880, 1815, 3719, 7582, 15397, 31171, 62952, 126891, 255379, 513342, 1030865, 2068495, 4147936, 8313583, 16655823, 33358014, 66791053, 133703499, 267603416, 535524643, 1071563515, 2143959070};
class Solution {
public:
  int findIntegers(int n) {
    // for(int i = 2; i < 31; ++i) {
    //   dp[i] = (1 << (i - 1)) + dp[i - 1] + dp[i - 2];
    // }
    // for(int i = 0; i < 31; ++i) {cout << dp[i] << endl;}
    int invalid = 0;
    for(int i = 30; i > 0; --i) {
      if(n & (1 << i)) {
        invalid += dp[i - 1];
        if(n & (1 << (i - 1))) {
          invalid += ((i == 30 ? INT_MAX : ((1 <<(i + 1)) - 1)) & n) - (1 << i) - (1 << (i - 1)) + 1;
          if(i > 1) invalid += dp[i - 2];
          break;
        }
      }
    }
    return n + 1 - invalid;
  }
};

// Accepted
// 527/527 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 90.24 % of cpp submissions (5.9 MB)
// @lc code=end

