/*
 * @lc app=leetcode id=2483 lang=cpp
 *
 * [2483] Minimum Penalty for a Shop
 */

// @lc code=start
class Solution {
public:
  int bestClosingTime(string customers) {
    int Y = 0;
    for(auto c : customers) {
      Y += 'Y' == c;
    }

    int answer = 0;
    int result = Y;
    int currentY = 0;
    int currentN = 0;
    for(int i = 0; i < customers.length(); ++i) {
      currentY += customers[i] == 'Y';
      currentN += customers[i] == 'N';
      if(result > (Y - currentY) + currentN) {
        result = Y - currentY + currentN;
        answer = i + 1;
      }
    }
    return answer;
  }
};

// Accepted
// 42/42 cases passed (11 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 86.38 % of cpp submissions (10.6 MB)
// @lc code=end

