/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
class Solution {
public:
  int numberOfSteps (int num) {
    if(!num) return num;
    int answer = 0;
    while(num) {
      answer += (num & 1) + 1;
      num >>= 1;
    }
    return answer - 1;
  }
};

// Accepted
// 204/204 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 26.52 % of cpp submissions (6 MB)
// @lc code=end

