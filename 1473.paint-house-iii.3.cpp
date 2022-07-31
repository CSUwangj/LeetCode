/*
 * @lc app=leetcode id=1473 lang=cpp
 *
 * [1473] Paint House III
 */

// @lc code=start
class Solution {
  bool noWay(const vector<int> &houses, int target, int m) {
    int pos = 0;
    while(pos < m && !houses[pos]) {
      pos += 1;
    }
    if(pos == m) return false;
    int current = houses[pos];
    int count = 1;
    for(;pos < m; ++pos) {
      if(houses[pos] && houses[pos] != current) {
        current = houses[pos];
        count += 1;
      }
    }
    return m < count;
  }
public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    if(noWay(houses, target, m)) return -1;
    int dp[m + 1][target + 1][n + 1];
    memset(dp, 0x33333333, sizeof(dp));
    memset(dp[0][0], 0, sizeof(dp[0][0]));
    for(int i = 0; i < m; ++i) {
      for(int j = 1; j <= target; ++j) {
        for(int k = 1; k <= n; ++k) {
          if(houses[i] && houses[i] != k) continue;
          dp[i + 1][j][k] = dp[i][j][k];
          for(int _k = 1; _k <= n; ++_k) {
            // cout << i << ' ' << j << ' ' << k << ' ' << _k << endl;
            if(_k == k) continue;
            dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j - 1][_k]);
          }
          if(!houses[i]) dp[i + 1][j][k] += cost[i][k - 1];
          // cout << "#" << i + 1 << ' ' << j << ' ' << k  << ' ' << dp[i + 1][j][k] << endl;
        }
      }
    }
    int result = *min_element(dp[m][target] + 1, dp[m][target] + n + 1);
    if(result >= 0x33333333) result = -1;
    return result;
  }
};

// Accepted
// 60/60 cases passed (79 ms)
// Your runtime beats 85.64 % of cpp submissions
// Your memory usage beats 92.29 % of cpp submissions (10.7 MB)
// @lc code=end

