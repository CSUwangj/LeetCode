/*
 * @lc app=leetcode id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 */

// @lc code=start
int dp[31] = {1, 2};
class Solution {
public:
  int findIntegers(int n) {
    for(int i = 2; i < 31; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    int prebit = 0;
    int answer = 0;
    for(int shift = 31; shift >= 0; --shift) {
      if(n & (1 << shift)) {
        answer += dp[shift];
        if(prebit) return answer;
        prebit = 1;
      } else {
        prebit = 0;
      }
    }
    return answer + 1;
  }
};

// Accepted
// 527/527 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.3 % of cpp submissions (5.8 MB)
// @lc code=end

