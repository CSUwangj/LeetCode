/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
class Solution {
public:
  int numberOfSteps (int num) {
    int answer = 0;
    while(num) {
      if(num % 2) num -= 1;
      else num >>= 1;
      ++answer;
    }
    return answer;
  }
};

// Accepted
// 204/204 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 74.11 % of cpp submissions (5.8 MB)
// @lc code=end

