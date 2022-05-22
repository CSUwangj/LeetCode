/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
  int countSubstrings(string s) {
    int dp[1001][1001] = {0};
    int len = s.length();
    int answer = len;
    for(int i = 0; i < len; ++i) {
      dp[i][i] = 1;
      dp[i][i + 1] = 1;
    }
    for(int l = 2; l <= len; ++l) {
      for(int j = 0; j + l <= len; ++j) {
        if(dp[j + 1][j + l - 1] && s[j] == s[j + l - 1]) {
          dp[j][j + l] = 1;
          answer += 1;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 130/130 cases passed (35 ms)
// Your runtime beats 29.77 % of cpp submissions
// Your memory usage beats 35.24 % of cpp submissions (10.8 MB)
// @lc code=end

