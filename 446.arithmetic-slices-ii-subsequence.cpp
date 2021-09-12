/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
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
  int numberOfArithmeticSlices(vector<int>& nums) {
    using ll = long long;
    int len = nums.size();
    int answer = 0;
    vector<unordered_map<ll, int>> dp(len);
    for(int i = 1; i < len; ++i) {
      for(int j = 0; j < i; ++j) {
        ll diff = (ll)nums[i] - nums[j];
        int result = dp[j].count(diff) ? dp[j][diff] : 0;
        dp[i][diff] += result + 1;
        answer += result;
      }
    }

    return answer;
  }
};

// Accepted
// 101/101 cases passed (901 ms)
// Your runtime beats 49.37 % of cpp submissions
// Your memory usage beats 39.87 % of cpp submissions (154.8 MB)
// @lc code=end

