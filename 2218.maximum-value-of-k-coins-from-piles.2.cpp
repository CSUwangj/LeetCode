/*
 * @lc app=leetcode id=2218 lang=cpp
 *
 * [2218] Maximum Value of K Coins From Piles
 */

// @lc code=start
class Solution {
public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int n = piles.size();
    for(auto &pile : piles) {
      for(int i = 1; i < pile.size(); ++i) {
        pile[i] += pile[i - 1];
      }
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for(int p = 0; p < n; ++p) {
      for(int i = 1; i <= k; ++i) {
        dp[p + 1][i] = dp[p][i];
        for(int j = 0; j < min<int>(i, piles[p].size()); ++j) {
          dp[p + 1][i] = max(dp[p + 1][i], dp[p][i - j - 1] + piles[p][j]);
        }
      }
    }

    // cout << dp << endl;

    return dp[n][k];
  }
};

// Accepted
// 122/122 cases passed (586 ms)
// Your runtime beats 14.4 % of cpp submissions
// Your memory usage beats 65.97 % of cpp submissions (18.2 MB)
// @lc code=end

