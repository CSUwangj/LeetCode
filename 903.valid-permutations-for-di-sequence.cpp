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
    for(int i = 0; i <= len; ++i) dp[0][i] = 1;
    for(int i = 1; i <= len; ++i) {
      for(int j = 0; j + i <= len; ++j) {
        if(s[i - 1] == 'D') {
          dp[i][j] = 0;
          for(int k = len; k > j; --k) {
            dp[i][j] += dp[i - 1][k];
            dp[i][j] %= MOD;
          }
        } else {
          dp[i][j] = 0;
          for(int k = 0; k <= j; ++k) {
            dp[i][j] += dp[i - 1][k];
            dp[i][j] %= MOD;
          }
        }
      }
    }
    int answer = 0;
    for(int i = 0; i <= len; ++i) {
      answer += dp[len][i];
      answer %= MOD;
    }
    return answer;
  }
};
// @lc code=end

