/*
 * @lc app=leetcode id=2466 lang=cpp
 *
 * [2466] Count Ways To Build Good Strings
 */

// @lc code=start
const int MOD = 1e9 + 7;
class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    int dp[high + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = min(zero, one); i <= high; ++i) {
      if(i >= zero) {
        dp[i] += dp[i - zero];
      }
      if(i >= one) {
        dp[i] += dp[i - one];
      }
      dp[i] %= MOD;
    }

    int answer = 0;
    for(int i = low; i <= high; ++i) {
      answer += dp[i];
      answer %= MOD;
    }

    return answer;
  }
};

// Accepted
// 36/36 cases passed (8 ms)
// Your runtime beats 94.56 % of cpp submissions
// Your memory usage beats 98.28 % of cpp submissions (6.5 MB)
// @lc code=end

