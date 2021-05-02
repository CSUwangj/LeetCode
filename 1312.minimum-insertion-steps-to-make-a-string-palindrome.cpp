/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
  int LCS(string &s1, string &s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    // cout << "$$$$$$";
    vector<vector<int>> dp(2, vector<int>(len2 + 1));
    for(int i = 0; i < len1; ++i) {
      for(int j = 1; j <= len2; ++j) {
        int parity = i & 1;
        dp[parity][j] = max(dp[!parity][j], dp[parity][j - 1]);
        if(s2[j - 1] == s1[i]) {
          dp[parity][j] = max(dp[parity][j], dp[!parity][j - 1] + 1);
        }
      }
    }
    return dp[!(len1 & 1)][len2];
  }
  bool isPalindrome(string &s) {
    int len = s.length();
    for(int i = 0; i * 2 < len; ++i) {
      if(s[i] != s[len - 1 - i]) return false;
    }
    return true;
  }
public:
  int minInsertions(string s) {
    if(isPalindrome(s)) return 0;
    string r = s;
    reverse(r.begin(), r.end());
    return s.length() - LCS(s, r);
  }
};

// @lc code=end

