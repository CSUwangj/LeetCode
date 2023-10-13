/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
class Solution {
public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int dp[501][501] = {};
    for(int i = 0; i < nums1.size(); ++i) {
      for(int j = 0; j < nums2.size(); ++j) {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        if(nums1[i] == nums2[j]) {
          dp[i + 1][j + 1] = max(dp[i][j] + 1, dp[i + 1][j + 1]);
        }
      }
    }

    return dp[nums1.size()][nums2.size()];
  }
};

// Accepted
// 74/74 cases passed (11 ms)
// Your runtime beats 90.52 % of cpp submissions
// Your memory usage beats 84.2 % of cpp submissions (10.6 MB)
// @lc code=end

