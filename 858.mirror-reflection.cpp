/*
 * @lc app=leetcode id=858 lang=cpp
 *
 * [858] Mirror Reflection
 */

// @lc code=start
class Solution {
  int gcd(int a, int b) {
    while(b) {
      int c = a;
      a = b;
      b = c % a;
    }
    return a;
  }
public:
  int mirrorReflection(int p, int q) {
    int metY = p*q/gcd(p, q);
    int metX = metY / q * p;
    int roundX = metX / p;
    int roundY = metY / p;
    
    if((roundY & roundX & 1) == 1) return 1;
    if((roundY & 1 == 1)) return 2;
    return 0;
  }
};

// Accepted
// 69/69 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 62.81 % of cpp submissions (5.9 MB)
// @lc code=end

