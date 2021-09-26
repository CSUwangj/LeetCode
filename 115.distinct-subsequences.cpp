/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
  int numDistinct(string s, string t) {
    int slen = s.length();
    int tlen = t.length();
    if(slen <= tlen) return s == t;
    // answer fits on a 32-bit signed integer doesn't means
    // mid values fit
    vector<long long> dp(tlen+1);
    dp[0] = 1;
    for(int i = 0; i < slen; ++i) {
      int beginPos = max(1, tlen-slen+i);
      int endPos = min(tlen, i+slen-tlen+1);
      for(int j = endPos; j >= beginPos; --j) {
        if(s[i] == t[j-1]) dp[j] += dp[j-1];
      }
    }
    // dp(slen+1)(tlen+1)
    // for(int i = 0; i < slen; ++i) {
    //     for(int j = 1; j < tlen; ++j){
    //         dp[i][j] = dp[i-1][j];
    //         if(s[i]==t[j]) dp[i][j] += dp[i-1][j-1];
    //     }
    // }
    return dp.back();
  }
};

// Accepted
// 63/63 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 97.33 % of cpp submissions (6.4 MB)
// @lc code=end

