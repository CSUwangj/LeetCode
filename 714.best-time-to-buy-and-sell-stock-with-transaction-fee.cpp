/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
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
  int maxProfit(vector<int>& prices, int fee) {
    int len = prices.size();
    if(len < 2) return 0;
    int sell = 0;
    int buy = INT_MIN;
    for(auto price : prices) {
      buy = max(buy, sell - fee - price);
      sell = max(sell, buy + price);
    }
    return sell;
  }
};

// Accepted
// 44/44 cases passed (83 ms)
// Your runtime beats 99.48 % of cpp submissions
// Your memory usage beats 99.75 % of cpp submissions (54.6 MB)
// @lc code=end

