/*
 * @lc app=leetcode id=1420 lang=cpp
 *
 * [1420] Build Array Where You Can Find The Maximum Exactly K Comparisons
 */

// @lc code=start
class Solution {
public:
  int numOfArrays(int n, int m, int k) {
    const int MOD = 1e9 + 7;
    int dp[51][101][51] = {};
    int pre[51][101][51] = {};
    for(int i = 0; i <= m; ++i) {
      dp[1][i][1] = 1;
      pre[1][i][1] = i;
    }

    for(int len = 2; len <= n; ++len) {
      for(int mmax = 1; mmax <= m; ++mmax) {
        for(int cost = 1; cost <= k; ++cost) {
          dp[len][mmax][cost] = (1LL * mmax * dp[len - 1][mmax][cost]) % MOD;
          
          dp[len][mmax][cost] += pre[len - 1][mmax - 1][cost - 1];
          dp[len][mmax][cost] %= MOD;

          pre[len][mmax][cost] = pre[len][mmax - 1][cost] + dp[len][mmax][cost];
          pre[len][mmax][cost] %= MOD;
        }
      }
    }

    return pre[n][m][k];
  }
};

// Accepted
// 28/28 cases passed (3 ms)
// Your runtime beats 98.62 % of cpp submissions
// Your memory usage beats 43.32 % of cpp submissions (8.5 MB)
// @lc code=end

