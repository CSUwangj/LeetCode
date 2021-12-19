/*
 * @lc app=leetcode id=902 lang=cpp
 *
 * [902] Numbers At Most N Given Digit Set
 */

// @lc code=start
class Solution {
  uint dp[12] = {0};
  uint prefix[10] = {0};
  vector<int> digit;
public:
  int atMostNGivenDigitSet(vector<string>& digits, int n) {
    int len = floor(log10(n)) + 1;
    for(auto &d : digits) {
      digit.push_back(d[0] - '0');
    }
    int curIndex = 0;
    for(int i = 1; i < 10; ++i) {
      prefix[i] = prefix[i - 1];
      if(curIndex < digit.size() && i >= digit[curIndex]) {
        prefix[i] += 1;
        curIndex += 1;
      }
    }
    dp[0] = 1;
    for(int i = 1; i <= len; ++i) {
      dp[i] = dp[i - 1] * digit.size();
    }
    int answer = 0;
    for(int i = len; i >= 0; --i) {
      if(!i) {
        answer += 1;
        break;
      }
      int curDigit = n / exp10(i - 1);
      curDigit %= 10;
      if(curDigit == 0) break;
      answer += prefix[curDigit - 1] * dp[i - 1];
      if(prefix[curDigit] - prefix[curDigit - 1] == 0){
        break;
      }
    }
    for(int i = 1; i < len; ++i) {
      answer += dp[i];
    }
    return answer;
  }
};

// Accepted
// 84/84 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 5.82 % of cpp submissions (8.3 MB)
// @lc code=end
