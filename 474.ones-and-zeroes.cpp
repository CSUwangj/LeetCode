/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    int count[len][2];
    for(int i = 0; i < len; ++i) {
      count[i][0] = 0;
      count[i][1] = 0;
      for(auto c : strs[i]) count[i][c == '1'] += 1;
    }
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; ++i) {
      for(int j = 0; j <= n; ++j) dp[i][j] = -1;
    }
    int answer = 0;
    dp[0][0] = 0;
    for(int i = 0; i < len; ++i) {
      for(int zero = m; zero >= count[i][0]; --zero) {
        for(int one = n; one >= count[i][1]; --one) {
          if(dp[zero - count[i][0]][one - count[i][1]] == -1) continue;
          dp[zero][one] = max(dp[zero - count[i][0]][one - count[i][1]] + 1, dp[zero][one]);
          answer = max(answer, dp[zero][one]);
        }
      }
    }
    
    return answer;
  }
};

// Accepted
// 71/71 cases passed (73 ms)
// Your runtime beats 98.35 % of cpp submissions
// Your memory usage beats 96.22 % of cpp submissions (8.7 MB)
// @lc code=end

