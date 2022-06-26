/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
      return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    vector<int> dp;
    for(auto &e : envelopes) {
      auto it = lower_bound(dp.begin(), dp.end(), e[1]);
      if(it == dp.end()) {
        dp.push_back(e[1]);
      } else {
        *it = e[1];
      }
    }
    return dp.size();
  }
};

// Accepted
// 231/231 cases passed (4 ms)
// Your runtime beats 73.76 % of cpp submissions
// Your memory usage beats 96.04 % of cpp submissions (6.7 MB)
// @lc code=end

