/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
constexpr int pop_count(int x) {
  const int m1  = 0X55555555;
  const int m2  = 0X33333333;
  const int m4  = 0X0F0F0F0F;
  const int m8  = 0X00FF00FF;
  const int m16 = 0X0000FFFF;
  x = (x &  m1) + ((x >>  1) &  m1);
  x = (x &  m2) + ((x >>  2) &  m2);
  x = (x &  m4) + ((x >>  4) &  m4);
  x = (x &  m8) + ((x >>  8) &  m8);
  x = (x & m16) + ((x >> 16) & m16);
  return x;
}
class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> answer(n + 1);
    for(int i = 1; i <= n; ++i) {
      answer[i] = pop_count(i);
    }
    return move(answer);
  }
};

// Accepted
// 15/15 cases passed (12 ms)
// Your runtime beats 25.62 % of cpp submissions
// Your memory usage beats 48.88 % of cpp submissions (8 MB)
// @lc code=end
