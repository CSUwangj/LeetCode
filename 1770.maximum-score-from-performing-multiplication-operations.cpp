/*
 * @lc app=leetcode id=1770 lang=cpp
 *
 * [1770] Maximum Score from Performing Multiplication Operations
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
constexpr int SZ = 1001;

class Solution {
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int m = multipliers.size();
    int len = nums.size();
    int dp[SZ][SZ] = {0};
    for(int i = 1; i <= m; ++i) {
      for(int j = 0; j <= i; ++j) {
        dp[i][j] = INT_MIN;
        if(j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums[j - 1] * multipliers[i - 1]);
        if(j != i) dp[i][j] = max(dp[i][j], dp[i - 1][j] + nums[len - i + j] * multipliers[i - 1]);
      }
    }
    
    int answer = INT_MIN;
    for(int i = 0; i <= m; ++i) answer = max(answer, dp[m][i]);
    
    return answer;
  }
};

// Accepted
// 50/50 cases passed (373 ms)
// Your runtime beats 95.59 % of cpp submissions
// Your memory usage beats 98.4 % of cpp submissions (54.7 MB)
// @lc code=end

