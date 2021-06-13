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
    int dp[len + 1][len + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= len; ++i) {
      for(int j = 0; j + i <= len; ++j) {
        int left = prefix[j + i - 1] - prefix[j] - dp[j][j + i - 1];
        int right = prefix[j + i] - prefix[j + 1] - dp[j + 1][j + i];
        dp[j][j + i] = max(left, right);
        // cout << j << ' ' << j << ' ' << dp[j][j + i] << endl;
      }
    }
    return dp[0][len];
  }
};
// @lc code=end

