/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
struct Table{
  constexpr Table() : values() {
    values[0] = 0;
    values[1] = 1;
    values[2] = 1;
    for(int i = 3; i < 38; ++i) {
      values[i] = values[i - 1] + values[i - 2] + values[i - 3];
    }
  }
  int values[38] = {};
};
constexpr auto table = Table();
class Solution {
public:
  int tribonacci(int n) {
    return table.values[n];
  }
};

// Accepted
// 39/39 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 47.39 % of cpp submissions (5.9 MB)
// @lc code=end

