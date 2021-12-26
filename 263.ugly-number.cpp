/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
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
  bool isUgly(int n) {
    if(n < 1) return false;
    while(n % 2 == 0) n /= 2;
    while(n % 3 == 0) n /= 3;
    while(n % 5 == 0) n /= 5;
    return n == 1;
  }
};

// Accepted
// 1013/1013 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 20.16 % of cpp submissions (6 MB)
// @lc code=end
