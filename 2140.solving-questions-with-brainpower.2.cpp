/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  long long solve(int index, const vector<vector<int>>& questions, vector<long long> &dp) {
    if(index >= questions.size()) return 0;
    if(dp[index]) return dp[index];

    long long take = questions[index][0] + solve(index + questions[index][1] + 1, questions, dp);
    long long leave = solve(index + 1, questions, dp);

    dp[index] = max(take, leave);
    return dp[index];
  }
public:
  long long mostPoints(vector<vector<int>>& questions) {
    vector<long long> dp(questions.size());

    return solve(0, questions, dp);
  }
};

// Accepted
// 54/54 cases passed (364 ms)
// Your runtime beats 82.02 % of cpp submissions
// Your memory usage beats 12.36 % of cpp submissions (124 MB)
// @lc code=end

