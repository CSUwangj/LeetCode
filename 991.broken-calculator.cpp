/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 */

// @lc code=start
class Solution {
public:
  int brokenCalc(int X, int Y) {
    int answer = 0;
    while(Y > X) {
        if(Y & 1) Y += 1;
        else Y /= 2;
        answer += 1;
    }
    return answer + X - Y;
  }
};

// Accepted
// 84/84 cases passed (3 ms)
// Your runtime beats 32.55 % of cpp submissions
// Your memory usage beats 73.18 % of cpp submissions (5.8 MB)
// @lc code=end
