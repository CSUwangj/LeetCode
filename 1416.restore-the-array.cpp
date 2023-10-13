/*
 * @lc app=leetcode id=1416 lang=cpp
 *
 * [1416] Restore The Array
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
  vector<int> dp;
  int solve(const string &s, int k, int pos) {
    if(pos == s.length()) return 1;
    if(s[pos] == '0') return 0;
    if(dp[pos] != -1) return dp[pos];
    int answer = 0;
    int num = 0;
    for(int j = pos; j < s.length(); ++j) {
      if((k - s[j] + '0') / 10 < num) break;
      num *= 10;
      num += s[j] - '0';
      answer += solve(s, k, j + 1);
      answer %= MOD;
    }

    return dp[pos] = answer;
  }
public:
  int numberOfArrays(string s, int k) {
    dp.resize(s.length(), -1);
    return solve(s, k, 0);
  }
};
// @lc code=end

