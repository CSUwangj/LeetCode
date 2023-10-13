/*
 * @lc app=leetcode id=956 lang=cpp
 *
 * [956] Tallest Billboard
 */

// @lc code=start
class Solution {
public:
  int tallestBillboard(vector<int>& rods) {
    int sum = 0;
    for(auto rod : rods) {
      sum += rod;
    }

    vector<int> dp(sum + 1, -1);
    dp[0] = 0;
    for(auto rod : rods) {
      vector<int> dpCopy(sum + 1);
      copy(dp.begin(), dp.end(), dpCopy.begin());

      for(int i = 0; i <= sum - rod; ++i) {
        if(dpCopy[i] < 0) continue;

        dp[i + rod] = max(dp[i + rod], dpCopy[i]);
        dp[abs(i - rod)] = max(dp[abs(i - rod)], dpCopy[i] + min(i, rod));
      }
    }

    return dp[0];
  }
};

// Accepted
// 80/80 cases passed (38 ms)
// Your runtime beats 95.24 % of cpp submissions
// Your memory usage beats 69.7 % of cpp submissions (26.6 MB)
// @lc code=end

