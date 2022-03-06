/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
const int MOD = 1e9 + 7;
constexpr auto table = []{
  array<int, 501> answer{0, 1};
  for(int i = 2; i <= 500; ++i) {
    answer[i] = 1LL * answer[i - 1] * i * (i * 2 - 1) % MOD;
  }
  return answer;
}();
class Solution {
public:
  int countOrders(int n) {
    return table[n];
  }
};

// Accepted
// 36/36 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 31.45 % of cpp submissions (6 MB)
// @lc code=end
