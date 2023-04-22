/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
class Solution {
  int len;
  const int MOD = 1e9 + 7;
  using pi = pair<int, int>;
  vector<pi> crimes;
  int dp[101][101][100];

  int solve(int restPeople, int restProfit, int position) {
    if(position == len || restPeople < crimes[position].first) {
      return restProfit <= 0;
    }
    restProfit = max(0, restProfit);
    if(dp[restPeople][restProfit][position] != -1) return dp[restPeople][restProfit][position];
    int result = solve(restPeople - crimes[position].first, restProfit - crimes[position].second, position + 1);
    result += solve(restPeople, restProfit, position + 1);
    result %= MOD;

    return dp[restPeople][restProfit][position] = result;
  }
public:
  int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    len = group.size();
    memset(dp, -1, sizeof(dp));
    crimes.reserve(len);
    for(int i = 0; i < len; ++i) {
      crimes.push_back({group[i], profit[i]});
    }
    sort(crimes.begin(), crimes.end());

    return solve(n, minProfit, 0);
  }
};

// Accepted
// 45/45 cases passed (120 ms)
// Your runtime beats 91.04 % of cpp submissions
// Your memory usage beats 54.72 % of cpp submissions (13 MB)
// @lc code=end

