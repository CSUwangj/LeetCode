/*
 * @lc app=leetcode id=1802 lang=cpp
 *
 * [1802] Maximum Value at a Given Index in a Bounded Array
 */

// @lc code=start
int64_t S(int64_t h, int64_t l) {
  return (2 * h - l + 1) * l / 2;
}

int FindExtra(int start, int increment, int maxSum) {
  int64_t b = start * 2 / increment - 1;
  int64_t c = 2 * maxSum / increment;

  int64_t d = sqrt(b * b + 4 * c);
  int n = (d - b) / 2;
  return n;
}

class Solution {
public:
  int maxValue(int n, int index, int maxSum) {
    maxSum -= n;
    int left = index + 1;
    int right = n - index;
    auto [small, large] = minmax(left, right);

    int64_t A = S(large, large) + S(large, small) - large;
    if(maxSum >= A) {
      return large + (maxSum - A) / n + 1;
    }
    int64_t B = S(small, small) * 2 - small;
    if(maxSum >= B) {
      return small + FindExtra(small * 2, 1, maxSum - B) + 1;
    }
    return FindExtra(1, 2, maxSum) + 1;
  }
};

// Accepted
// 370/370 cases passed (4 ms)
// Your runtime beats 42.79 % of cpp submissions
// Your memory usage beats 46.27 % of cpp submissions (6 MB)
// @lc code=end

