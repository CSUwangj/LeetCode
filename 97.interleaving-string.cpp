/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();
    if(len1 + len2 != len3) return false;
    bool dp[len2 + 1];
    for(int i = 0; i <= len1; ++i) {
      for(int j = 0; j <= len2; ++j) {
        if(!i && !j) {
          dp[j] = true;
        } else if(!i) {
          dp[j] = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
        } else if(!j) {
          dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
        } else {
          dp[j] = (dp[j - 1] && (s2[j - 1] == s3[i + j - 1])) ||
                  (dp[j] && (s1[i - 1] == s3[i + j - 1]));
        }
      }
    }
    return dp[len2];
  }
};
// @lc code=end

