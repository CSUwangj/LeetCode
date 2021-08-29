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
class Solution {
public:
  bool judgeSquareSum(int c) {
    for(int i = 2; i * i <= c; ++i) {
      if(c % i == 0) {
        int count = 0;
        while(c % i == 0) {
          count += 1;
          c /= i;
        }
        if(i % 4 == 3 && (count & 1)) {
          return false;
        }
      }
    }
    return c % 4 != 3;
  }
};

// Accepted
// 124/124 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 11.27 % of cpp submissions (6 MB)
// @lc code=end

