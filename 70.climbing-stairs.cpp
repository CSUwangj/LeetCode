/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
constexpr auto table = []{
  array<int, 46> arr{1, 1};
  for(int i = 2; i < 46; ++i) arr[i] = arr[i - 1] + arr[i - 2];
  return arr;
}();
class Solution {
public:
  int climbStairs(int n) {
    return table[n];
  }
};

// Accepted
// 45/45 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 55.72 % of cpp submissions (6 MB)
// @lc code=end

