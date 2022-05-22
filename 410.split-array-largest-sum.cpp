/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int dp[50][1000];
  int len;
  int solve(const vector<int> &prefix, int current, int rest) {
    if(dp[rest][current]) return dp[rest][current];
    if(!rest) {
      dp[rest][current] = prefix[len] - prefix[current];
      return dp[rest][current];
    }
    int result = INT_MAX;
    for(int i = current; i < len - rest; ++i) {
      int currentSum = prefix[i + 1] - prefix[current];
      int largstSum = max(currentSum, solve(prefix, i + 1, rest - 1));
      result = min(result, largstSum);
      if(currentSum >= result) break;
    }
    dp[rest][current] = result;
    return result;
  }
public:
  int splitArray(vector<int>& nums, int m) {
    len = nums.size();
    vector<int> prefix(len + 1);
    for(int i = 0; i < len; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }
    return solve(prefix, 0, m - 1);
  }
};

// Accepted
// 30/30 cases passed (64 ms)
// Your runtime beats 23.90 % of cpp submissions
// Your memory usage beats 25.68 % of cpp submissions (7.5 MB)
// @lc code=end
