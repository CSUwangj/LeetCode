/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

int dp[101][32];

class Solution {
  int dfs(const vector<int> &prefix, int pos, int m, int result = INT_MIN) {
    if(pos + m * 2 > prefix.size()) return prefix.back() - (pos ? prefix[pos - 1] : 0);
    if(dp[pos][m]) return dp[pos][m];
    for(int i = pos; i < pos + m * 2; ++i) {
      result = max(result, prefix[i] - (pos ? prefix[pos - 1] : 0) - dfs(prefix, i + 1, max(m, i - pos + 1)));
    }
    dp[pos][m] = result;
    return dp[pos][m];
  }
public:
  int stoneGameII(vector<int>& piles) {
    memset(dp, 0, sizeof(dp));
    partial_sum(piles.begin(), piles.end(), piles.begin());
    return (piles.back() + dfs(piles, 0, 1)) / 2;
  }
};

// Accepted
// 92/92 cases passed (13 ms)
// Your runtime beats 74.27 % of cpp submissions
// Your memory usage beats 80.14 % of cpp submissions (8.4 MB)
// @lc code=end
