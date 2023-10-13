/*
 * @lc app=leetcode id=920 lang=cpp
 *
 * [920] Number of Music Playlists
 */

// @lc code=start
class Solution {
  using ll = long long;
  const int MOD = 1e9 + 7;
public:
  int numMusicPlaylists(int n, int goal, int k) {
    vector<vector<ll>> dp(2, vector<ll>(n + 1));
    dp[0][0] = 1;
    
    for(int i = 1; i <= goal; ++i) {
      int parity = i & 1;
      dp[parity][0] = 0;
      for(int j = 1; j <= min(i, n); ++j) {
        dp[parity][j] = dp[parity ^ 1][j - 1] * (n - j + 1);
        dp[parity][j] %= MOD;
        if(i > k) {
          dp[parity][j] += dp[parity ^ 1][j] * (j - k);
          dp[parity][j] %= MOD;
        }
      }
    }

    return dp[goal & 1][n];
  }
};

// Accepted
// 83/83 cases passed (3 ms)
// Your runtime beats 83.78 % of cpp submissions
// Your memory usage beats 61.26 % of cpp submissions (6.3 MB)
// @lc code=end

