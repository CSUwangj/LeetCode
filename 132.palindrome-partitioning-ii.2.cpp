/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool isPalindrome(string &s, int start, int end) {
    while(start < end) {
      if(s[start++] != s[end--]) return false;
    }
    return true;
  }
public:
  int minCut(string s) {
    int len = s.length();
    if(isPalindrome(s, 0, len - 1)) return 0;
    for(int i = 1; i < len - 1; ++i) {
      if(isPalindrome(s, 0, i) && isPalindrome(s, i + 1, len - 1)) return 1;
    }
    vector<int> dp;
    dp.push_back(-1);
    for(int i = 0; i < len; ++i) {
      dp.push_back(i);
    }
    int pLen;
    for(int i = 0; i < len; ++i) {
      pLen = 0;
      while(i - pLen >= 0 && i + pLen < len && s[i - pLen] == s[i + pLen]) {
        dp[i + pLen + 1] = min(dp[i + pLen + 1], dp[i - pLen] + 1);
        pLen += 1;
      }
      pLen = 0;
      while(i - pLen >= 0 && i + pLen + 1 < len && s[i - pLen] == s[i + pLen + 1]) {
        dp[i + pLen + 2] = min(dp[i + pLen + 2], dp[i - pLen] + 1);
        pLen += 1;
      }
    }

    return dp.back();
  }
};
// Accepted
// 33/33 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 87.96 % of cpp submissions (6.5 MB)
// @lc code=end

