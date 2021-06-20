/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 */

// @lc code=start
constexpr long long zeros(long long x) {
  long long result = 0;
  while(x) {
    result += x / 5;
    x /= 5;
  }
  return result;
}
class Solution {
public:
  int preimageSizeFZF(int k) {
    long long start = 0;
    long long end = LONG_LONG_MAX;
    while(start < end) {
      auto mid = (start + end) >> 1;
      if(zeros(mid) < k) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    int begin = start;
    if(zeros(start) != k) return 0;
    start = 0;
    end = LONG_LONG_MAX - 1;
    while(start < end) {
      auto mid = (start + end + 1) >> 1;
      if(zeros(mid) > k) {
        end = mid - 1;
      } else {
        start = mid;
      }
    }
    return start - begin + 1;
  }
};
// @lc code=end

