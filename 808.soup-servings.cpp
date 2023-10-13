/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
vector<vector<double>> dp(193, vector<double>(193, -1));
class Solution {
  double solve(int a, int b) {
    if(a <= 0 && b <= 0) {
      return 0.5;
    } else if(a <= 0) {
      return 1.0;
    } else if(b <= 0) {
      return 0;
    } else if(dp[a][b] >= 0) {
      return dp[a][b];
    }
    dp[a][b] = 0.25 * (solve(a - 4, b) + solve(a - 3, b - 1) + solve(a - 2, b - 2) + solve(a - 1, b - 3));
    return dp[a][b];
  }
public:
  double soupServings(int n) {
    if(n > 4800) return 1;
    n += 24;
    n /= 25;
    return solve(n, n);
  }
};

// Accepted
// 41/41 cases passed (2 ms)
// Your runtime beats 87.45 % of cpp submissions
// Your memory usage beats 87.45 % of cpp submissions (6.4 MB)
// @lc code=end