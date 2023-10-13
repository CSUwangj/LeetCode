/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
public:
  bool PredictTheWinner(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> dp(len, vector<int>(len));
    for(int i = 0; i < len; ++i) {
      dp[i][i] = nums[i];
    }
    for(int i = 1; i < len; ++i) {
      for(int j = 0; j+i < len; ++j) {
        dp[j][j+i] = max(nums[j]-dp[j+1][j+i], nums[j+i]-dp[j][j+i-1]);
      }
    }
    return dp[0][len-1] >= 0;
  }
};

// Accepted
// 62/62 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 29.3 % of cpp submissions (7.6 MB)
// @lc code=end

