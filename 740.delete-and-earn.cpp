/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    int dp[10001] = {};
    int count[10001] = {};
    for(auto num : nums) {
      count[num] += 1;
    }
    dp[1] = count[1];
    for(int i = 2; i <= 10000; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + i * count[i]);
    }
    return dp[10000];
  }
};

// Accepted
// 48/48 cases passed (3 ms)
// Your runtime beats 97.58 % of cpp submissions
// Your memory usage beats 90.77 % of cpp submissions (9.2 MB)
// @lc code=end
