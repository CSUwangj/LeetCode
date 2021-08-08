/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[501][501];
class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    int len = piles.size();
    for(int i = 0; i < len; ++i) {
      dp[i][i] = 0;
      dp[i][i + 1] = piles[i];
    }
    for(int i = 2; i <= len; ++i) {
      if(i & 1) {
        for(int j = 0; j + i <= len; ++j) {
          dp[j][j + i] = max(dp[j][j + i - 1] + piles[j + i - 1], dp[j + 1][j + i] + piles[j]);
        }
      } else {
        for(int j = 0; i + j <= len; ++j) {
          dp[j][j + i] = min(dp[j][j + i - 1] - piles[j + i - 1], dp[j + 1][j + i] - piles[j]);
        }
      }
    }
    return dp[0][len] < 0;
  }
};

// Accepted
// 46/46 cases passed (8 ms)
// Your runtime beats 53.22 % of cpp submissions
// Your memory usage beats 48.67 % of cpp submissions (8.5 MB)
// @lc code=end

