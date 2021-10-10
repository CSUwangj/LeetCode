/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int dp[2][1001] = {};
public:
  int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length();
    int len2 = text2.length();
    for(int i = 0; i < len1; ++i) {
      int parity =  i & 1;
      for(int j = 0; j < len2; ++j) {
        dp[parity][j + 1] = max({dp[!parity][j + 1], dp[parity][j], dp[!parity][j] + (text1[i] == text2[j])});
      }
    }
    return dp[~len1 & 1][len2];
  }
};

// Accepted
// 44/44 cases passed (35 ms)
// Your runtime beats 20.16 % of cpp submissions
// Your memory usage beats 98.32 % of cpp submissions (6.4 MB)
// @lc code=end

