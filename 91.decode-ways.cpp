/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
  int numDecodings(string s) {
    int len = s.length();
    vector<int> dp(len+1);
    dp[0] = 1;
    for(int i = 0; i < len; ++i) {
      if(s[i] > '0') {
        dp[i+1] = dp[i];
      } 
      if(i) {
        int code = (s[i-1]-'0')*10 + s[i]-'0';
        if(code > 9 && code < 27) {
          dp[i+1] += dp[i-1];
        }
      }
    }
    return dp.back();
  }
};

// Accepted
// 269/269 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 68.77 % of cpp submissions (6.2 MB)
// @lc code=end

