/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

// @lc code=start
class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(costs.begin(), costs.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] - a[1] < b[0] - b[1];
    });
    int len = costs.size();
    int answer = 0;
    for(int i = 0; i * 2 < len; ++i) {
      answer += costs[i][0] + costs[len - 1 - i][1];
    }
    return answer;
  }
};

// Accepted
// 50/50 cases passed (4 ms)
// Your runtime beats 78.71 % of cpp submissions
// Your memory usage beats 78.35 % of cpp submissions (7.9 MB)
// @lc code=end
