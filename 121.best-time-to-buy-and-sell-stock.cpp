/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int mmin;
    int answer = 0;
    for(auto price : prices) {
      mmin = min(mmin, price);
      answer = max(answer, price - mmin);
    }
    return answer;
  }
};

// Accepted
// 211/211 cases passed (134 ms)
// Your runtime beats 78.62 % of cpp submissions
// Your memory usage beats 56.82 % of cpp submissions (93.4 MB)
// @lc code=end
