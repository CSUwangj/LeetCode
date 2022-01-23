/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

class Solution {
public:
  int stoneGameII(vector<int>& piles) {
    int len = piles.size();
    vector<int> suffixSum(len + 1);
    for(int i = len - 1; i >= 0; --i) {
      suffixSum[i] = suffixSum[i + 1] + piles[i];
    }
    vector<vector<int>> dp(len + 1, vector<int>(len + 1));
    for(int i = 0; i <= len; ++i) {
      dp[i][len] = suffixSum[i];
    }
    for(int i = len - 1; i >= 0; --i) {
      for(int j = len - 1; j >= 1; --j) {
        for(int X = 1; X <= 2 * j && X + i <= len; ++X) {
          dp[i][j] = max(dp[i][j], suffixSum[i] - dp[i + X][max(j, X)]);
        }
      }
    }

    return dp[0][1];
  }
};

// Accepted
// 92/92 cases passed (140 ms)
// Your runtime beats 22.12 % of cpp submissions
// Your memory usage beats 48.08 % of cpp submissions (10.1 MB)
// @lc code=end
