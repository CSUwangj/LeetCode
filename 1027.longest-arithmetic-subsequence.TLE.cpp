/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
class Solution {
public:
  int longestArithSeqLength(vector<int>& nums) {
    int len = nums.size();
    if(len < 2) return len;

    vector<map<int, int>> dp(len + 1);
    int answer = 1;
    for(int i = 1; i < len; ++i) {
      for(int j = 0; j < i; ++j) {
        int diff = nums[j] - nums[i];
        int count = 1;

        if(dp[j].count(diff)) {
          count = dp[j][diff];
        }

        dp[i][diff] = 1 + count;
        answer = max(answer, dp[i][diff]);
      }
    }

    return answer;
  }
};
// @lc code=end

