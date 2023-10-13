/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    int dp[amount + 1];
    for(int i = 0; i <= amount; ++i) dp[i] = 0;
    dp[0] = 1;
    for(auto c : coins) {
      for(int i = c; i <= amount; ++i) {
        dp[i] += dp[i - c];
      }
    }
    return dp[amount];
  }
};

// Accepted
// 280/280 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 95.27 % of cpp submissions (7 MB)
// @lc code=end

