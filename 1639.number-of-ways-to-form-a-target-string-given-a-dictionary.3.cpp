/*
 * @lc app=leetcode id=1639 lang=cpp
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  const int MOD = 1e9 + 7;
public:
  int numWays(vector<string>& words, string target) {
    int wordLen = words.front().length();
    int targetLen = target.length();
    if(targetLen > wordLen) return 0;
    vector<vector<int>> count(wordLen + 1, vector<int>(26));

    for(const auto &word : words) {
      for(int i = 0; i < wordLen; ++i) {
        count[i][word[i] - 'a'] += 1;
      }
    }
    vector<int> dp(targetLen + 1);
    dp[0] = 1;

    for(int i = 0; i < wordLen; ++i) {
      for(int j = targetLen - 1; j >= i; --j) {
        dp[j + 1] += (int)(1LL * dp[j] * count[i][target[j] - 'a'] % MOD);
        dp[j + 1] %= MOD;
      }
    }

    return dp[targetLen];
  }
};

// Accepted
// 89/89 cases passed (203 ms)
// Your runtime beats 90.52 % of cpp submissions
// Your memory usage beats 77.59 % of cpp submissions (28.2 MB)
// @lc code=end

