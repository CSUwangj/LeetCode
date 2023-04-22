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
    vector<vector<int>> count(26, vector<int>(wordLen + 1));

    for(const auto &word : words) {
      for(int i = 0; i < wordLen; ++i) {
        count[word[i] - 'a'][i] += 1;
      }
    }

    for(int c = 0; c < 26; ++c) {
      for(int i = wordLen - 1; i >= 0; --i) {
        count[c][i] += count[c][i + 1];
      }
    }
    vector<vector<int>> dp(wordLen + 1, vector<int>(targetLen, -1));

    function<int(int, int)> solve = [&](int wordPos, int targetPos) {
      if(targetPos == targetLen) return 1;
      if(dp[wordPos][targetPos] != -1) return dp[wordPos][targetPos];
      int c = target[targetPos] - 'a';
      long long result = 0;
      int originalPos = wordPos;
      for(int pos = wordPos; count[c][pos] && wordLen - pos >= targetLen - targetPos; ++pos) {
        if(count[c][pos] - count[c][pos + 1]) {
          result += 1LL * (count[c][pos] - count[c][pos + 1]) * solve(pos + 1, targetPos + 1);
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
// 89/89 cases passed (760 ms)
// Your runtime beats 5.18 % of cpp submissions
// Your memory usage beats 48.28 % of cpp submissions (53.8 MB)
// @lc code=end

