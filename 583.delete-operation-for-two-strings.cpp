/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
  int LCS(string &s1, string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    int dp[2][len2 + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < len1; ++i) {
      for(int j = 1; j <= len2; ++j) {
        int parity = i & 1;
        dp[parity][j] = max(dp[!parity][j], dp[parity][j - 1]);
        if(s2[j - 1] == s1[i]) {
          dp[parity][j] = max(dp[parity][j], dp[!parity][j - 1] + 1);
        }
      }
    }
    return dp[!(len1 & 1)][len2];
  }
public:
  int minDistance(string s1, string s2) {
    return s1.length() + s2.length() - LCS(s1, s2) * 2;
  }
};

// Accepted
// 1306/1306 cases passed (17 ms)
// Your runtime beats 77.81 % of cpp submissions
// Your memory usage beats 99.74 % of cpp submissions (6.4 MB)
// @lc code=end

