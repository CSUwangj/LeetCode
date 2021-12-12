/*
 * @lc app=leetcode id=878 lang=cpp
 *
 * [878] Nth Magical Number
 */

// @lc code=start
const int MOD = 1e9 + 7;
constexpr int lcm(int a, int b) {
  int originA = a;
  int originB = b;
  int c = a % b;
  while(c) {
    a = b;
    b = c;
    c = a % b;
  }
  return originA / b * originB;
}
constexpr int findOffset(int a, int b, int g, int rest) {
  unsigned int low = 0;
  unsigned int high = g;
  while(low < high) {
    unsigned int mid = (low + high) >> 1;
    if(mid / a + mid / b < rest) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low % MOD;
}
class Solution {
public:
  int nthMagicalNumber(int n, int a, int b) {
    if(a < b) swap(a, b);
    if(!(a % b)) return 1LL * n * b % MOD;
    int g = lcm(a, b);
    int count = g / a + g / b - 1;
    int whole = 1LL * g * (n / count) % MOD;
    return (whole + findOffset(a, b, g, n % count)) % MOD;
  }
};

// Accepted
// 70/70 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 94.83 % of cpp submissions (5.7 MB)
// @lc code=end
