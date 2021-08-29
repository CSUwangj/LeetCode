/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
constexpr auto table = []{
  array<long long, 46342> arr{0};
  for(int i = 1; i < 46341; ++i) arr[i] = i * i;
  arr[46341] = 1LL + INT_MAX;
  return arr;
}();
class Solution {
public:
  bool judgeSquareSum(int c) {
    int begin = 0;
    int end = lower_bound(table.begin(), table.end(), c) - table.begin();
    while(begin <= end) {
      long long result = table[begin] + table[end];
      if(result == c) return true;
      if(result < c) {
        begin += 1;
      } else {
        end -= 1;
      }
    }
    return false;
  }
};

// Accepted
// 124/124 cases passed (4 ms)
// Your runtime beats 54.21 % of cpp submissions
// Your memory usage beats 10.72 % of cpp submissions (6.4 MB)
// @lc code=end

