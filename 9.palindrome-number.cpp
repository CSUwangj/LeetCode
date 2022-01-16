/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int reverse(int x) {
    int result = 0;
    while(x && INT_MAX / 10 > result) {
      result *= 10;
      result += x % 10;
      x /= 10;
    }
    return result;
  }
public:
  bool isPalindrome(int x) {
    return x >= 0 && x == reverse(x);
  }
};

// Accepted
// 11510/11510 cases passed (17 ms)
// Your runtime beats 34.59 % of cpp submissions
// Your memory usage beats 31.34 % of cpp submissions (6 MB)
// @lc code=end
