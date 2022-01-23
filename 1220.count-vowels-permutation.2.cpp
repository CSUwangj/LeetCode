/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[2][5];
const int MOD = 1e9 + 7;
class Solution {
public:
  int countVowelPermutation(int n) {
    for(int i = 0; i < 5; ++i) dp[1][i] = 1;
    for(int l = 1; l <= n; ++l) {
      int parity = l & 1;
      for(int v = 0; v < 5; ++v) {
        dp[!parity][v] = 0;
      }
      dp[!parity][1] = (dp[!parity][1] + dp[parity][0]) % MOD;
      dp[!parity][0] = (dp[!parity][0] + dp[parity][1]) % MOD;
      dp[!parity][2] = (dp[!parity][2] + dp[parity][1]) % MOD;
      dp[!parity][2] = (dp[!parity][2] + dp[parity][3]) % MOD;
      dp[!parity][4] = (dp[!parity][4] + dp[parity][3]) % MOD;
      dp[!parity][0] = (dp[!parity][0] + dp[parity][4]) % MOD;
      for(int v = 0; v < 5; ++v) {
        if(v == 2) continue;
        dp[!parity][v] = (dp[!parity][v] + dp[parity][2]) % MOD;
      }
    }

    int answer = 0;
    for(int v = 0; v < 5; ++v) {
      answer += dp[n & 1][v];
      answer %= MOD;
    }
    return answer;
  }
};

// Accepted
// 43/43 cases passed (4 ms)
// Your runtime beats 86.19 % of cpp submissions
// Your memory usage beats 99.49 % of cpp submissions (5.8 MB)
// @lc code=end

