/*
 * @lc app=leetcode id=1201 lang=cpp
 *
 * [1201] Ugly Number III
 */

// @lc code=start
constexpr long long mylcm(long long x, long long y) {
  return x / gcd(x, y) * y;
}
class Solution {
public:
  int nthUglyNumber(int n, int a, int b, int c) {
    long long high = 2000000000;
    long long low = 1;
    while(low < high) {
      long long mid = (low + high) >> 1;
      long long count = mid / a + mid / b + mid / c \
                  - mid / mylcm(a, b) - mid / mylcm(a, c) - mid / mylcm(b, c) \
                  + mid / mylcm(a, mylcm(b, c));
      // cout << mid << ' ' << count << endl;
      if(count < n) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
};

// Accepted
// 53/53 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 29.3 % of cpp submissions (5.9 MB)
// @lc code=end
