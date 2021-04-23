/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 */

// @lc code=start
const int MOD = 1e9 + 7;
class Solution {
public:
  int numDecodings(string s) {
    int len = s.length();
    vector<long long> dp(len + 1);
    dp[0] = 1;
    for(int i = 0; i < len; ++i) {
      char prev = i ? s[i - 1] : -1;
      if(s[i] == '*') {
        dp[i + 1] = dp[i] * 9;
        if(prev == '1') dp[i + 1] += dp[i - 1] * 9;
        if(prev == '2') dp[i + 1] += dp[i - 1] * 6;
        if(prev == '*') dp[i + 1] += dp[i - 1] * 15;
      } else {
        if(s[i] < '7' && (prev == '2' || prev == '*')) dp[i + 1] += dp[i - 1];
        if(prev == '1' || prev == '*') dp[i + 1] += dp[i - 1];
        if(s[i] != '0') dp[i + 1] += dp[i];
      }
      dp[i + 1] %= MOD;
      if(!dp[i] && !dp[i + 1]) return 0;
      // cout << dp[i + 1][10] << ' ';
    }
    // cout << endl;
    return dp.back();
  }
};
// @lc code=end

