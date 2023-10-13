/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}
class Solution {
public:
  double myPow(double x, int n) {
    int sign = sgn(n);
    n = abs(n);
    double result = 1;
    double base = x;
    while(n) {
      if(n & 1) result *= base;
      base *= base;
      n /= 2;
    }
    return sign == -1 ? 1 / result : 1 * result;
  }
};

// Accepted
// 306/306 cases passed (4 ms)
// Your runtime beats 40.18 % of cpp submissions
// Your memory usage beats 62.65 % of cpp submissions (5.9 MB)
// @lc code=end
