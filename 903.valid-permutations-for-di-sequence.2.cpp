/*
 * @lc app=leetcode id=903 lang=cpp
 *
 * [903] Valid Permutations for DI Sequence
 */

// @lc code=start
const int MOD = 1e9 + 7;
class Solution {
public:
  int numPermsDISequence(string s) {
    int dp[201][201] = {};
    int len = s.length();
    for(int i = 0; i <= len; ++i) dp[0][i] = 1 + i;
    for(int i = 1; i <= len; ++i) {
      for(int j = 0; j <= len; ++j) {
        if(j + i > len) {
          dp[i][j] = dp[i][j - 1];
        } else if(s[i - 1] == 'D') {
          dp[i][j] = dp[i - 1][len] - dp[i - 1][j] + MOD;
          dp[i][j] %= MOD;
        } else {
          dp[i][j] = dp[i - 1][j];
        }
        if(j + i <= len && j) {
          dp[i][j] += j ? dp[i][j - 1] : 0;
          dp[i][j] %= MOD;
        }
        // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
      }
    }
    return dp[len][len];
  }
};
// @lc code=end

