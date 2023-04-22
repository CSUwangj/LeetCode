/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */

// @lc code=start
class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int dp[366] = {};
    int pos = 0;
    int ranges[3] = {1, 7, 30};
    for(int i = 1; i < 366; ++i) {
      if(pos >= days.size() || days[pos] > i) {
        dp[i] = dp[i - 1];
        continue;
      }
      pos += 1;
      dp[i] = INT_MAX;
      for(int t = 0; t < 3; ++t) {
        if(i >= ranges[t]) {
          dp[i] = min(dp[i], dp[i - ranges[t]] + costs[t]);
        } else {
          dp[i] = min(dp[i], costs[t]);
        }
      }
    }

    return dp[365];
  }
};

// Accepted
// 69/69 cases passed (4 ms)
// Your runtime beats 69.83 % of cpp submissions
// Your memory usage beats 91.47 % of cpp submissions (9.4 MB)
// @lc code=end

