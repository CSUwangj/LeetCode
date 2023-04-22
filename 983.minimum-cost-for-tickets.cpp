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
    for(int i = 1; i < 366; ++i) {
      if(pos >= days.size() || days[pos] > i) {
        dp[i] = dp[i - 1];
        continue;
      }
      pos += 1;
      dp[i] = dp[i - 1] + costs[0];
      if(i > 6) {
        dp[i] = min(dp[i], dp[i - 7] + costs[1]);
      } else {
        dp[i] = min(dp[i], costs[1]);
      }

      if(i > 29) {
        dp[i] = min(dp[i], dp[i - 30] + costs[2]);
      } else {
        dp[i] = min(dp[i], costs[2]);
      }
    }

    return dp[365];
  }
};

// Accepted
// 69/69 cases passed (8 ms)
// Your runtime beats 30.37 % of cpp submissions
// Your memory usage beats 91.47 % of cpp submissions (9.4 MB)
// @lc code=end

