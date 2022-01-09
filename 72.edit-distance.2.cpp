/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
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
  int minDistance(string word1, string word2) {
    int dp[2][501];
    int len1 = word1.length();
    int len2 = word2.length();
    for(int j = 0; j <= len2; ++j) {
      dp[0][j] = j;
    }
    for(int i = 0; i < len1; ++i) {
      int parity = (i & 1);
      dp[parity ^ 1][0] = i + 1;
      for(int j = 0; j < len2; ++j) {
        dp[parity ^ 1][j + 1] = min(dp[parity][j + 1], dp[parity ^ 1][j]) + 1;
        int cost = (word1[i] != word2[j]);
        dp[parity ^ 1][j + 1] = min(dp[parity ^ 1][j + 1], dp[parity][j] + cost);
      }
    }
    return dp[len1 & 1][len2];
  }
};

// Accepted
// 1146/1146 cases passed (4 ms)
// Your runtime beats 97.26 % of cpp submissions
// Your memory usage beats 99.64 % of cpp submissions (6.2 MB)
// @lc code=end
