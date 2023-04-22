/*
 * @lc app=leetcode id=2218 lang=cpp
 *
 * [2218] Maximum Value of K Coins From Piles
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
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    int n = piles.size();
    for(auto &pile : piles) {
      for(int i = 1; i < pile.size(); ++i) {
        pile[i] += pile[i - 1];
      }
    }
    vector<vector<int>> dp(n, vector<int>(k + 1));

    function<int(int, int)> solve = [&](int pile, int rest) {
      if(!rest || pile == n) return 0;
      if(dp[pile][rest]) return dp[pile][rest];
      int result = solve(pile + 1, rest);
      for(int i = 0; i < piles[pile].size() && i < rest; ++i) {
        result = max(result, piles[pile][i] + solve(pile + 1, rest - i - 1));
      }

      return dp[pile][rest] = result;
    };

    return solve(0, k);
  }
};

// Accepted
// 122/122 cases passed (447 ms)
// Your runtime beats 23.03 % of cpp submissions
// Your memory usage beats 46.34 % of cpp submissions (18.4 MB)
// @lc code=end

