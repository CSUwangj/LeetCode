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
    int dp[501][501];
    int len1 = word1.length();
    int len2 = word2.length();
    for(int i = 0; i <= len1; ++i) {
      dp[i][0] = i;
    }
    for(int j = 0; j <= len2; ++j) {
      dp[0][j] = j;
    }
    for(int i = 0; i < len1; ++i) {
      for(int j = 0; j < len2; ++j) {
        dp[i + 1][j + 1] = min(dp[i][j + 1], dp[i + 1][j]) + 1;
        if(word1[i] != word2[j]) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
        else dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
        cout << dp[i + 1][j + 1] << ' ';
      }
      cout << endl;
    }
    return dp[len1][len2];
  }
};

// Accepted
// 1146/1146 cases passed (24 ms)
// Your runtime beats 27.06 % of cpp submissions
// Your memory usage beats 82.21 % of cpp submissions (7.2 MB)
// @lc code=end
