/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
int a[502];
int dp[502][502];
class Solution {
public:
  int maxCoins(vector<int>& nums) {
    memset(dp, 0, sizeof(dp));
    int n = nums.size();
    
    a[0] = 1;
    a[n+1] = 1;
    for(int i = 0; i < n; i++) {
      a[i+1] = nums[i];
    }
    
    for(int l = 3; l <= n+2; l++) {
      for(int i = 0; i + l - 1 <= n + 1; i++){
        for(int j = 1; j <= l - 2; j++){
          dp[i][i+l-1] = max(dp[i][i + j] + dp[i + j][i+l-1] + a[i] * a[i+j] * a[i + l - 1], dp[i][i+l-1]);
        }
      }
    }
    return dp[0][n+1];
  }
};

// Accepted
// 70/70 cases passed (128 ms)
// Your runtime beats 99.93 % of cpp submissions
// Your memory usage beats 95.76 % of cpp submissions (8.9 MB)
// @lc code=end
