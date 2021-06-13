/*
 * @lc app=leetcode id=1690 lang=cpp
 *
 * [1690] Stone Game VII
 */

// @lc code=start
class Solution {
public:
  int stoneGameVII(vector<int>& stones) {
    int len = stones.size();
    int prefix[len + 1];
    prefix[0] = 0;
    for (int i = 0; i < len; ++i) prefix[i + 1] = prefix[i] + stones[i];
    int dp[len + 1][len + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i <= len; ++i) {
      bool parity = i & 1;
      for(int j = 0; j + i <= len; ++j) {
        if(prefix[j + i] - prefix[j + 1] + dp[j + 1][j + i][parity] - dp[j + 1][j + i][!parity] >
           prefix[j + i - 1] - prefix[j] + dp[j][j + i - 1][parity] - dp[j][j + i - 1][!parity]) {
          dp[j][j + i][parity] = prefix[j + i] - prefix[j + 1] + dp[j + 1][j + i][parity];
          dp[j][j + i][!parity] = dp[j + 1][j + i][!parity];
        } else {
          dp[j][j + i][parity] = prefix[j + i - 1] - prefix[j] + dp[j][j + i - 1][parity];
          dp[j][j + i][!parity] = dp[j][j + i - 1][!parity];
        }
      }
    }
    return abs(dp[0][len][0] - dp[0][len][1]);
  }
};
// @lc code=end

