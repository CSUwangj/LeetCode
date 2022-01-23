/*
 * @lc app=leetcode id=1510 lang=cpp
 *
 * [1510] Stone Game IV
 */

// @lc code=start
constexpr int LIMIT = 100000;
auto table = [](){
  array<bool, LIMIT + 1> arr{false};
  for(int i = 0; i <= LIMIT; ++i) {
    if(arr[i]) continue;
    for(int j = 1; j * j + i <= LIMIT; ++j) {
      arr[i + j * j] = true;
    }
  }
  return arr;
}();
class Solution {
public:
  bool winnerSquareGame(int n) {
    return table[n];
  }
};

// Accepted
// 72/72 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.92 % of cpp submissions (6 MB)
// @lc code=end
