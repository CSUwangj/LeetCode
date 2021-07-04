/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
int dp[2][5];
const int MOD = 1e9 + 7;
class Solution {
public:
  int countVowelPermutation(int n) {
    for(int i = 0; i < 5; ++i) dp[1][i] = 1;
    for(int l = 2; l <= n; ++l) {
      int parity = l & 1;
      dp[parity][3] = dp[!parity][2];
      dp[parity][4] = (dp[!parity][2] + dp[!parity][3]) % MOD;
      dp[parity][1] = (dp[!parity][2] + dp[!parity][0]) % MOD;
      dp[parity][0] = (dp[!parity][1] + dp[!parity][4]) % MOD;
      dp[parity][0] = (dp[parity][0] + dp[!parity][2]) % MOD;
      dp[parity][2] = (dp[!parity][3] + dp[!parity][1]) % MOD;
    }

    int answer = 0;
    for(int v = 0; v < 5; ++v) {
      answer += dp[n & 1][v];
      answer %= MOD;
    }
    return answer;
  }
};
// @lc code=end

