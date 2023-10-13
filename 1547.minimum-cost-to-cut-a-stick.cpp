/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

// @lc code=start
class Solution {
  vector<vector<int>> dp;
  int solve(
    const vector<int> &cuts,
    int stickLeft,
    int stickRight,
    int cutLeft,
    int cutRight
  ) {
    if(cutLeft >= cutRight) return 0;
    // int pos = lower_bound(cuts.begin() + cutLeft, cuts.begin() + cutRight, (stickLeft + stickRight) / 2) - cuts.begin();
    // int subCost = INT_MAX;
    // cout << cutLeft << ' ' << cutRight << ' ' << stickLeft << ' ' << stickRight << endl;
    // if(pos + 1 < cutRight) {
    //   subCost = min(subCost,
    //     solve(cuts, stickLeft, cuts[pos + 1], cutLeft, pos + 1) + solve(cuts, cuts[pos], stickRight, pos + 2, cutRight));
    // }
    // if(pos < cutRight) {
    //   subCost = min(subCost,
    //     solve(cuts, stickLeft, cuts[pos], cutLeft, pos) + solve(cuts, cuts[pos], stickRight, pos + 1, cutRight));
    // }
    // if(pos > cutLeft) {
    //   subCost = min(subCost,
    //     solve(cuts, stickLeft, cuts[pos - 1], cutLeft, pos - 1) + solve(cuts, cuts[pos - 1], stickRight, pos, cutRight));
    // }
    if(dp[cutLeft][cutRight] != -1) {
      return dp[cutLeft][cutRight];
    }
    int subCost = INT_MAX;
    for(int i = cutLeft; i < cutRight; ++i) {
      subCost = min(subCost,
        solve(cuts, stickLeft, cuts[i], cutLeft, i) + solve(cuts, cuts[i], stickRight, i + 1, cutRight));
    }

    return dp[cutLeft][cutRight] = stickRight - stickLeft + subCost;
  }
public:
  int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    dp.resize(cuts.size(), vector<int>(cuts.size() + 1, -1));

    return solve(cuts, 0, n, 0, cuts.size());
  }
};

// Accepted
// 100/100 cases passed (137 ms)
// Your runtime beats 12.26 % of cpp submissions
// Your memory usage beats 80.63 % of cpp submissions (10.2 MB)
// @lc code=end

