/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
int dp[2][1001];
const int MOD = 1e9 + 7;
class Solution {
public:
  int numRollsToTarget(int d, int f, int target) {
    if(d * f < target || d > target) return 0;
    if(d == target) return 1;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= d; ++i) {
      int parity = i & 1;
      for(int j = 0; j < i; ++j) {
        dp[parity][j] = 0;
      }
      for(int j = i; j <= i * f; ++j) {
        dp[parity][j] = 0;
        for(int k = 1; k <= f; ++k) {
          if(j - k < 0) continue;
          dp[parity][j] += dp[!parity][j - k];
          dp[parity][j] %= MOD;
        }
      }
      // for(int j = 0; j <= i * f; ++j) {
      //   cout << dp[parity][j] << ' ';
      // }
      // cout << endl;
    }
    return dp[d & 1][target];
  }
};
// @lc code=end

