/*
 * @lc app=leetcode id=1187 lang=cpp
 *
 * [1187] Make Array Strictly Increasing
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
    int pos,
    int left,
    const vector<int> &arr1,
    const vector<int> &arr2,
    vector<map<int, int>> &dp
  ) {
    if(pos == arr1.size()) return 0;

    if(dp[pos].count(left)) return dp[pos][left];

    int exclude = INT_MAX;
    int include = INT_MAX;

    if(arr1[pos] > left) {
      exclude = solve(pos + 1, arr1[pos], arr1, arr2, dp);
    }
    int replace = upper_bound(arr2.begin(), arr2.end(), left) - arr2.begin();
    if(replace != arr2.size()) {
      include = solve(pos + 1, arr2[replace], arr1, arr2, dp);
    }
    if(include == INT_MAX) {
      dp[pos][left] = exclude;
    } else {
      dp[pos][left] = min(exclude, include + 1);
    }
    return dp[pos][left];
  }
public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    sort(arr2.begin(), arr2.end());
    vector<map<int, int>> dp(2001);

    int result = solve(0, INT_MIN, arr1, arr2, dp);
    if(result == INT_MAX) return -1;
    return result;
  }
};

// Accepted
// 21/21 cases passed (897 ms)
// Your runtime beats 12.21 % of cpp submissions
// Your memory usage beats 11.05 % of cpp submissions (80.1 MB)
// @lc code=end

