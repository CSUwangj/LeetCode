/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
  int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int buy[len];
    int sell[len];
    buy[0] = -prices[0];
    sell[0] = 0;
    for(int i = 1; i < len; ++i) {
      buy[i] = max(buy[i - 1], -prices[i]);
      sell[i] = 0;
    }
    for(int i = 1; i <= k; ++i) {
      for(int j = 1; j < len; ++j) {
        sell[j] = max(sell[j], sell[j - 1]);
        sell[j] = max(sell[j], buy[j - 1] + prices[j]);
      }
      for(int j = 1; j < len; ++j) {
        buy[j] = max(buy[j - 1], sell[j - 1] - prices[j]);
      }
    }
    return sell[len - 1];
  }
public:
  int maxProfit(vector<int>& prices) {
    return maxProfit(2, prices);
  }
};

// Accepted
// 214/214 cases passed (124 ms)
// Your runtime beats 83.81 % of cpp submissions
// Your memory usage beats 61.08 % of cpp submissions (76 MB)
// @lc code=end

