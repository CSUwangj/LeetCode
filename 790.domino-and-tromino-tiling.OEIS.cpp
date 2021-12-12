/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MOD = 1e9 + 7;
constexpr auto table = []{
  array<int, 1001> table{1, 1, 2};
  for(int i = 3; i < 1001; ++i) {
    table[i] = 2 * table[i - 1] % MOD + table[i - 3];
    table[i] %= MOD;
  }
  return table;
}();

class Solution {
public:
  int numTilings(int n) {
    return table[n];
  }
};

// Accepted
// 39/39 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 60.67 % of cpp submissions (6.1 MB)
// @lc code=end
