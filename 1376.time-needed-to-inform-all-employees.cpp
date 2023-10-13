/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int solve(
    int current,
    const vector<vector<int>> &subordinates,
    const vector<int>& informTime
  ) {
    int subResult = 0;
    for(auto subordinate : subordinates[current]) {
      subResult = max(subResult, solve(subordinate, subordinates, informTime));
    }

    return informTime[current] + subResult;
  }
public:
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    if(n == 1) return 0;
    vector<vector<int>> subordinates(n);
    for(int i = 0; i < n; ++i) {
      if(manager[i] == -1) continue;
      subordinates[manager[i]].push_back(i);
    }

    int answer = 0;
    return solve(headID, subordinates, informTime);
  }
};

// Accepted
// 39/39 cases passed (260 ms)
// Your runtime beats 90.17 % of cpp submissions
// Your memory usage beats 59.75 % of cpp submissions (121.9 MB)
// @lc code=end

