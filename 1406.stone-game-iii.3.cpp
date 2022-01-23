/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[50000 + 3];
class Solution {
public:
  string stoneGameIII(vector<int>& stoneValue) {
    int len = stoneValue.size();
    for(int i = 0; i < 3; ++i) {
      stoneValue.push_back(0);
    }
    partial_sum(stoneValue.begin(), stoneValue.end(), stoneValue.begin());
    for(int i = 0; i < 3; ++i) {
      dp[len + i] = 0;
    }
    for(int i = len - 1; i >= 0; --i) {
      dp[i] = INT_MIN;
      for(int j = 0; j < 3; ++j) {
        dp[i] = max(dp[i], stoneValue[i + j] - (i ? stoneValue[i - 1] : 0) - dp[i + j + 1]);
      }
    }
    if(dp[0] > 0) return "Alice";
    if(dp[0] < 0) return "Bob";
    return "Tie";
  }
};

// Accepted
// 185/185 cases passed (226 ms)
// Your runtime beats 64.45 % of cpp submissions
// Your memory usage beats 87.54 % of cpp submissions (126.6 MB)
// @lc code=end
