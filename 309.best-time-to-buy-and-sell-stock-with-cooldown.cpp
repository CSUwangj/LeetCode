/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len < 2) return 0;
    int buy[2] = {-prices[0], max(-prices[0], -prices[1])};
    int sell[2] = {0, max(0, buy[1] + prices[1])};
    for(int i = 2; i < len; ++i) {
      buy[0] = buy[1];
      buy[1] = max(buy[1], sell[0] - prices[i]);
      sell[0] = sell[1];
      sell[1] = max(sell[1], buy[0] + prices[i]);
    }
    return sell[1];
  }
};

// Accepted
// 210/210 cases passed (8 ms)
// Your runtime beats 32.2 % of cpp submissions
// Your memory usage beats 49.7 % of cpp submissions (11.3 MB)
// @lc code=end

