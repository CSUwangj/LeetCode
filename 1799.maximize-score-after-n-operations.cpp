/*
 * @lc app=leetcode id=1799 lang=cpp
 *
 * [1799] Maximize Score After N Operations
 */

// @lc code=start
class Solution {
  int len;
  int n;
  int solve(
    vector<int>& dp,
    vector<vector<int>>& gcd,
    int mask,
    int ops
  ) {
    if(ops > n) return 0;
    if(dp[mask]) return dp[mask];

    int result = 0;
    for(int i = 0; i < len; ++i) {
      if(mask & (1 << i)) continue;
      for(int j = 0; j < len; ++j) {
        if(i == j) continue;
        if(mask & (1 << j)) continue;
        int newMask = mask | (1 << i) | (1 << j);
        result = max(result, ops * gcd[i][j] + solve(dp, gcd, newMask, ops + 1));
      }
    }

    return dp[mask] = result;
  }
public:
  int maxScore(vector<int>& nums) {
    len = nums.size();
    n = len / 2;
    vector<int> dp(1 << len);
    vector<vector<int>> gcd(len, vector<int>(len));

    for(int i = 0; i < len; ++i) {
      for(int j = i + 1; j < len; ++j) {
        gcd[i][j] = gcd[j][i] = __gcd(nums[i], nums[j]);
      }
    }
    return solve(dp, gcd, 0, 1);
  }
};

// Accepted
// 76/76 cases passed (156 ms)
// Your runtime beats 72.32 % of cpp submissions
// Your memory usage beats 49.83 % of cpp submissions (9 MB)
// @lc code=end

