/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount+1);
    dp[0] = 0;
    for(auto coin : coins){
      for(int i = coin; i <= amount; ++i) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
    return dp.back() > amount ? -1 : dp.back();
  }
};

// Accepted
// 188/188 cases passed (108 ms)
// Your runtime beats 58.8 % of cpp submissions
// Your memory usage beats 68.59 % of cpp submissions (14.3 MB)
// @lc code=end

