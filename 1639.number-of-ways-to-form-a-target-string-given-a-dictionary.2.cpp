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

    for(int c = 0; c < 26; ++c) {
      for(int i = wordLen - 1; i >= 0; --i) {
        count[i][c] += count[i + 1][c];
      }
    }
    vector<vector<int>> dp(wordLen + 1, vector<int>(targetLen, -1));

    function<int(int, int)> solve = [&](int wordPos, int targetPos) {
      if(targetPos == targetLen) return 1;
      if(dp[wordPos][targetPos] != -1) return dp[wordPos][targetPos];
      int c = target[targetPos] - 'a';
      long long result = 0;
      int originalPos = wordPos;
      for(int pos = wordPos; count[pos][c] && wordLen - pos >= targetLen - targetPos; ++pos) {
        if(count[pos][c] - count[pos + 1][c]) {
          result += 1LL * (count[pos][c] - count[pos + 1][c]) * solve(pos + 1, targetPos + 1);
          result %= MOD;
        }
      }
      dp[wordPos][targetPos] = result;
      return dp[wordPos][targetPos];
    };

    // solve(0, 0);
    // cout << count << endl;
    // cout << dp << endl;
    // return dp[0][0];
    return solve(0, 0);
  }
};

// Accepted
// 89/89 cases passed (875 ms)
// Your runtime beats 5.18 % of cpp submissions
// Your memory usage beats 45.26 % of cpp submissions (54.4 MB)
// @lc code=end

