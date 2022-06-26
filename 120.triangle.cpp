/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = triangle.front().front();
    for(int i = 1; i < n; ++i) {
      for(int j = i; j >= 0; --j) {
        if(j == i) dp[j] = dp[j - 1];
        else if(j) dp[j] = min(dp[j], dp[j - 1]);
        dp[j] += triangle[i][j];
      }
    }
    return *min_element(dp.begin(), dp.end());
  }
};

// Accepted
// 44/44 cases passed (2 ms)
// Your runtime beats 98.01 % of cpp submissions
// Your memory usage beats 70.75 % of cpp submissions (8.6 MB)
// @lc code=end

