/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
  bool isPowerOfFour(int n) {
    if(n < 1) return false;
    double p = log(n) / log(4);
    double diff = abs(p - floor(p));
    return diff < numeric_limits<double>::epsilon();  
  }
};
// @lc code=end

