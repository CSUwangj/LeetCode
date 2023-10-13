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

    int dp[len + 1][1001];
    memset(dp, 0, sizeof(dp));
    int answer = 1;
    for(int i = 1; i < len; ++i) {
      for(int j = 0; j < i; ++j) {
        int diff = nums[j] - nums[i] + 500;
        int count = 1;

        if(dp[j][diff]) {
          count = dp[j][diff];
        }

        dp[i][diff] = 1 + count;
        answer = max(answer, dp[i][diff]);
      }
    }

    return answer;
  }
};

// Accepted
// 63/63 cases passed (148 ms)
// Your runtime beats 96.32 % of cpp submissions
// Your memory usage beats 93.59 % of cpp submissions (13.9 MB)
// @lc code=end

