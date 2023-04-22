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
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for(int p = 0; p < n; ++p) {
      dp[p + 1] = dp[p];
      int sum = 0;
      for(int i = 0; i < min<int>(piles[p].size(), k); ++i) {
        sum += piles[p][i];
        for(int j = 0; j + i + 1 <= k; ++j) {
          // cout << p + 1 << ' ' << j + i + 1 <<  ' ' << j << endl;
          dp[p + 1][j + i + 1] = max(dp[p + 1][j + i + 1], dp[p][j] + sum);
        }
        // cout << "OUT!?" << endl;
      }
    }

    return dp[n][k];
  }
};

// Accepted
// 122/122 cases passed (391 ms)
// Your runtime beats 29.06 % of cpp submissions
// Your memory usage beats 65.97 % of cpp submissions (18.1 MB)
// @lc code=end

