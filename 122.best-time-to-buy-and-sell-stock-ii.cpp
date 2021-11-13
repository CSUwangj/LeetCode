/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int answer = 0;
    for(int i = 1; i < len; ++i) {
      if(prices[i] > prices[i - 1]) answer += prices[i] - prices[i - 1];
    }
    return answer;
  }
};

// Accepted
// 200/200 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 8.25 % of cpp submissions (13.1 MB)
// @lc code=end

