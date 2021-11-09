/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
constexpr auto result = []{
  array<int, 20> arr{1, 1};
  for(int i = 2; i < 20; ++i) {
    for(int j = 0; j < i; ++j) {
      arr[i] += arr[j] * arr[i - j - 1];
    }
  }
  return arr;
}();
class Solution {
public:
  int numTrees(int n) {
    return result[n];
  }
};

// Accepted
// 19/19 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 64.16 % of cpp submissions (5.9 MB)
// @lc code=end

