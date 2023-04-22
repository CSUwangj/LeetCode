/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    int len = s.length();
    vector<int> dp(len), dp_(len), dp__(len);

    for(int l = 1; l <= len; ++l) {
      for(int i = 0; i < len - l + 1; ++i) {
        int j = i + l - 1;
        if(l == 1) {
          dp[j] = 1;
        } else if(s[i] == s[j]) {
          dp[j] = dp__[j - 1] + 2;
        } else {
          dp[j] = max(dp_[j], dp_[j - 1]);
        }
      }
      swap(dp__, dp_);
      dp_ = dp;
    }
    
    return dp.back();
  }
};

// Accepted
// 86/86 cases passed (80 ms)
// Your runtime beats 88.97 % of cpp submissions
// Your memory usage beats 88.37 % of cpp submissions (6.7 MB)
// @lc code=end

