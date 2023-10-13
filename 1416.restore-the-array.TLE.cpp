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
  unordered_map<string_view, int> memo;
  string mmax;
  bool lessS(const string_view &a, const string_view &b) {
    return a.length() < b.length() || (a.length() == b.length() && a < b);
  }
  int solve(const string_view &substr) {
    if(memo.count(substr)) return memo[substr];
    int result = !lessS(mmax, substr);
    for(int i = 1; i < substr.length(); ++i) {
      if(substr[i] == '0') continue;
      if(lessS(mmax, substr.substr(0, i))) break;
      result += 1LL * solve(substr.substr(i));
      result %= MOD;
    }
    // cout << substr << ": " << result << endl;
    return memo[substr] = result;
  }
public:
  int numberOfArrays(string s, int k) {
    mmax = to_string(k);
    return solve(s);
  }
};
// @lc code=end

