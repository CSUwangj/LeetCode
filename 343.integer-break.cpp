/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
public:
  int integerBreak(int n) {
    int answer = 0;
    int k = 1;
    do {
      k += 1;
      int result = 1;
      int base = n / k;
      int reminder = n % k;
      for(int i = 0; i < n % k; ++i) {
        result *= base + 1;
      }
      for(int i = 0; i < k - n % k; ++i) {
        result *= base;
      }
      answer = max(result, answer);
    }while(k < n);
    return answer;
  }
};

// Accepted
// 50/50 cases passed (2 ms)
// Your runtime beats 49.96 % of cpp submissions
// Your memory usage beats 36.38 % of cpp submissions (6.3 MB)
// @lc code=end

