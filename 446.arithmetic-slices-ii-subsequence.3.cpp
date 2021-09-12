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
    map<int, vector<int>> indices;
    for(int i = 0; i < len; ++i) {
      indices[nums[i]].push_back(i);
    }
    vector<vector<int>> dp(len, vector<int>(len));
    for(int i = 1; i < len; ++i) {
      for(int j = 0; j < i; ++j) {
        ll k = 2LL * nums[j] - nums[i];
        if(k > INT_MAX || k < INT_MIN) continue;
        if(indices.count(k)) {
          for(auto index : indices[k]) {
            if(index >= j) break;
            dp[j][i] += dp[index][j] + 1;
          }
        }
        answer += dp[j][i];
      }
    }

    return answer;
  }
};

// Accepted
// 101/101 cases passed (192 ms)
// Your runtime beats 94.46 % of cpp submissions
// Your memory usage beats 95.73 % of cpp submissions (29.8 MB)
// @lc code=end

