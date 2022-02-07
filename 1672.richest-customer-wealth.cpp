/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
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
  int maximumWealth(vector<vector<int>>& accounts) {
    int answer = 0;
    for(auto &account : accounts) {
      answer = max(answer, accumulate(account.begin(), account.end(), 0));
    }
    return answer;
  }
};

// Accepted
// 34/34 cases passed (4 ms)
// Your runtime beats 90.57 % of cpp submissions
// Your memory usage beats 49.93 % of cpp submissions (7.9 MB)
// @lc code=end