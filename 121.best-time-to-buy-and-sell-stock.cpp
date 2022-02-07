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
// 211/211 cases passed (163 ms)
// Your runtime beats 48.73 % of cpp submissions
// Your memory usage beats 90.32 % of cpp submissions (93.3 MB)
// @lc code=end
