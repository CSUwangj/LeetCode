/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
class Solution {
public:
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    int len = jobDifficulty.size();
    if(len < d) return -1;
    if(len == d) return accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
    int dp[d][len];
    dp[0][0] = jobDifficulty[0];
    for(int i = 1; i < len; ++i) dp[0][i] = max(dp[0][i - 1], jobDifficulty[i]);
    for(int i = 1; i < d; ++i) {
      vector<int> monoStack;
      for(int j = i; j < len; ++j) {
        dp[i][j] = dp[i - 1][j - 1] + jobDifficulty[j];
        while(monoStack.size() && jobDifficulty[monoStack.back()] < jobDifficulty[j]) {
          dp[i][j] = min(dp[i][j], dp[i][monoStack.back()] - jobDifficulty[monoStack.back()] + jobDifficulty[j]);
          monoStack.pop_back();
        }
        if(monoStack.size()) {
          dp[i][j] = min(dp[i][j], dp[i][monoStack.back()]);
        }
        monoStack.push_back(j);
      }
    }
    return dp[d - 1][len - 1];
  }
};

// Accepted
// 34/34 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 83.12 % of cpp submissions (7.3 MB)
// @lc code=end

