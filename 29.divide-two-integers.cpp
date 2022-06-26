/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
  int answer = 0;
  int minus(int current, int base, int resultBase) {
    if(current > base) {
      return current;
    }
    if(base >= INT_MIN / 2) current = minus(current, base + base, resultBase + resultBase);
    if(current > base) {
      return current;
    }
    current -= base;
    answer += resultBase;
    return current;
  }
public:
  int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    int sign = 1;
    if(dividend > 0) {
      sign = -1;
      dividend = 0 - dividend;
    }
    if(divisor > 0) {
      sign = sign == 1 ? -1 : 1;
      divisor = 0 - divisor;
    }
    minus(dividend, divisor, -1);
    answer = sign == 1 ? 0 - answer : answer;
    return answer;
  }
};

// Accepted
// 992/992 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 76.09 % of cpp submissions (5.9 MB)
// @lc code=end

