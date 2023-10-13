/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

// @lc code=start
class Solution {
public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int dp[2][501] = {};
    for(int i = 0; i < nums1.size(); ++i) {
      bool row = (i & 1);
      for(int j = 0; j < nums2.size(); ++j) {
        dp[!row][j + 1] = max(dp[!row][j], dp[row][j + 1]);
        if(nums1[i] == nums2[j]) {
          dp[!row][j + 1] = max(dp[row][j] + 1, dp[!row][j + 1]);
        }
      }
    }

    return dp[nums1.size() & 1][nums2.size()];
  }
};

// Accepted
// 74/74 cases passed (16 ms)
// Your runtime beats 78.67 % of cpp submissions
// Your memory usage beats 99.68 % of cpp submissions (9.5 MB)
// @lc code=end

