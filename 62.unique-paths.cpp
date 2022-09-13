/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
constexpr int combination(int total, int pick) {
  long long result = 1;
  for(int i = 0; i < pick; ++i) {
    result *= (total - i);
    result /= (i + 1);
  }
  return result;
}

class Solution {
public:
  int uniquePaths(int m, int n) {
    return combination(m + n - 2, min(n - 1, m - 1));
  }
};

// Accepted
// 63/63 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 98.48 % of cpp submissions (5.8 MB)
// @lc code=end

