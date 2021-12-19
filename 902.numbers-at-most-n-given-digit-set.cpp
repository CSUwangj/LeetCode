/*
 * @lc app=leetcode id=902 lang=cpp
 *
 * [902] Numbers At Most N Given Digit Set
 */

// @lc code=start
#define MOD 1000000007
class Solution {
  int dp[11][10] = {};
  int nDigits[11] = {};
  bool digits[10] = {};
public:
  int atMostNGivenDigitSet(vector<string>& ds, int n) {
    for(auto &d : ds) {
      digits[d[0] - '0'] = true;
    }
    int nLen = floor(log10(n)) + 1;
    for(int i = 1; i <= nLen; ++i) {
      nDigits[i] = n % 10;
      n /= 10;
    }
    dp[0][9] = 1;
    for(int i = 1; i <= nLen; ++i) {
      for(int j = 1; j < 10; ++j) {
        dp[i][j] = dp[i][j - 1];
        if(digits[j]) {
          dp[i][j] += dp[i - 1][9];
          dp[i][j] %= MOD;
        }
      }
    }
    int answer = 0;
    for(int i = 1; i < nLen; ++i) {
      answer += dp[i][9];
    }
    for(int i = nLen; i ; --i) {
      if(!nDigits[i]) break;
      answer += dp[1][nDigits[i] - 1] * dp[i - 1][9];
      if(!digits[nDigits[i]]) break;
    }
    bool consN = true;
    for(int i = 1; i <= nLen; ++i) {
      if(!digits[nDigits[i]]) consN = false;
    }
    answer += consN;
    return answer;
  }
};

// Accepted
// 84/84 cases passed (0 ms)
// Your runtime beats 100.0 % of cpp submissions
// Your memory usage beats 22.22 % of cpp submissions (8.3 MB)
// @lc code=end
