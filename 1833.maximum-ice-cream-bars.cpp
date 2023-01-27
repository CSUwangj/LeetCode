/*
 * @lc app=leetcode id=1833 lang=cpp
 *
 * [1833] Maximum Ice Cream Bars
 */

// @lc code=start
class Solution {
public:
  int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    if(coins < costs.front()) {
      return 0;
    }
    int answer = 0;
    for(int i = 1; i < costs.size(); ++i) {
      costs[i] += costs[i - 1];
      if(coins < costs[i]) {
        return i;
      }
    }
    return costs.size();
  }
};

// Accepted
// 63/63 cases passed (193 ms)
// Your runtime beats 91.54 % of cpp submissions
// Your memory usage beats 76.68 % of cpp submissions (76.5 MB)
// @lc code=end

