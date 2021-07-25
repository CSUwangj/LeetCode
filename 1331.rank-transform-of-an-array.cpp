/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

// @lc code=start
class Solution {
public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> order(arr);
    sort(order.begin(), order.end());
    order.resize(unique(order.begin(), order.end()) - order.begin());
    unordered_map<int, int> rk;
    int count = 0;
    for(auto i : order) rk[i] = ++count;
    for(auto &i : arr) i = rk[i];
    return arr;
  }
};

// Accepted
// 37/37 cases passed (84 ms)
// Your runtime beats 89.57 % of cpp submissions
// Your memory usage beats 72.51 % of cpp submissions (39.1 MB)
// @lc code=end

