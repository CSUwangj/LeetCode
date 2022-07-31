/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int dp[3];
    int len = cost.size();
    for(int i = 2; i <= len; ++i) {
      dp[i % 3] = min(dp[(i + 1) % 3] + cost[i - 2], dp[(i + 2) % 3] + cost[i - 1]);
    }
    return dp[len % 3];
  }
};

// Accepted
// 283/283 cases passed (11 ms)
// Your runtime beats 53.51 % of cpp submissions
// Your memory usage beats 79.79 % of cpp submissions (13.6 MB)
// @lc code=end

