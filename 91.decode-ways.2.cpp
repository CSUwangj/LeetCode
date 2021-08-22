/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int numDecodings(string s) {
    int len = s.length();
    int dp = 1;
    int dp_ = 0;
    for(int i = 0; i < len && dp; i++) {
      int nextDP = 0;
      if(s[i] > '0') {
        nextDP = dp;
      }
      if(i) {
        int code = (s[i - 1] - '0') * 10 + s[i] - '0';
        if(code > 9 && code < 27) {
          nextDP += dp_;
        }
      }
      dp_ = dp;
      dp = nextDP;
    }
    return dp;
  }
};

// Accepted
// 269/269 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 90.44 % of cpp submissions (6.1 MB)
// @lc code=end

