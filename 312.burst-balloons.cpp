/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution {
public:
  int maxCoins(vector<int>& n) {
    vector<int> nums{1};
    nums.reserve(n.size() + 2);
    for(auto i : n) if(i) nums.push_back(i);
    nums.push_back(1);
    int len = nums.size() - 2;
    int dp[len + 2][len + 2];
    memset(dp, 0, sizeof(dp));

    // minus two '1'
    // cout << len << endl;
    for(int l = 0; l < len; ++l) {
      for(int begin = 1; begin + l <= len; ++begin) {
        for(int choose = begin; choose <= begin + l; ++choose) {
          dp[begin][begin + l] = max(
            dp[begin][begin + l],
            dp[choose + 1][begin + l] + dp[begin][choose - 1] + nums[begin - 1] * nums[choose] * nums[begin + l + 1]
          );
        }
        // cout << "dp[" << begin << "][" << begin + l << "]: " << dp[begin][begin + l] << endl;
      }
    }
    return dp[1][len];
  }
};

// Accepted
// 70/70 cases passed (316 ms)
// Your runtime beats 88.51 % of cpp submissions
// Your memory usage beats 71.84 % of cpp submissions (9.2 MB)
// @lc code=end
