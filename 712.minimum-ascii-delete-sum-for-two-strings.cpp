/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    int len1 = s1.length(), len2 = s2.length();
    vector<int> dp(len2+1);
    for(int i = 0; i < len1; ++i) {
      int prev = 0;
      for(int j = 1; j <= len2; ++j) {
        int originVal = dp[j];
        dp[j] = max(dp[j], dp[j - 1]);
        if(s2[j - 1] == s1[i]) dp[j] = max(dp[j], prev + s1[i]);
        prev = originVal;
      }
    }
    int sum = 0;
    for(auto c : s1) sum += c;
    for(auto c : s2) sum += c;
    return sum - 2 * dp.back();
  }
};

// Accepted
// 93/93 cases passed (24 ms)
// Your runtime beats 90.09 % of cpp submissions
// Your memory usage beats 96.88 % of cpp submissions (6.6 MB)
// @lc code=end

