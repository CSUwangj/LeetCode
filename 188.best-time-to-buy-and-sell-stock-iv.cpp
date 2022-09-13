/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
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
    // cout << "$$$$$$$$$$$$$$$" << endl;
    for(int i = 1; i <= k; ++i) {
      for(int j = 1; j < len; ++j) {
        sell[j] = max(sell[j], sell[j - 1]);
        sell[j] = max(sell[j], buy[j - 1] + prices[j]);
      }
      for(int j = 1; j < len; ++j) {
        buy[j] = max(buy[j - 1], sell[j - 1] - prices[j]);
      }
      // for(int j = 0; j < len; ++j) {
      //   cout << i << ' ' << j << ' ' << buy[j] << ' ' << sell[j] << endl;
      // }
    }
    return sell[len - 1];
  }
};

// Accepted
// 211/211 cases passed (3 ms)
// Your runtime beats 99.03 % of cpp submissions
// Your memory usage beats 98.77 % of cpp submissions (10.6 MB)
// @lc code=end

