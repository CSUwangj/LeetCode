/*
 * @lc app=leetcode id=1575 lang=cpp
 *
 * [1575] Count All Possible Routes
 */

// @lc code=start
class Solution {
  const int MOD = 1e9 + 7;
  vector<vector<int>> dp;
  int memo(vector<int> &locations, int curCity, int finish, int fuel) {
    if(fuel < 0) return 0;
    if(dp[curCity][fuel] != -1) return dp[curCity][fuel];
    int answer = curCity == finish;
    for(int nextCity = 0; nextCity < locations.size(); ++nextCity) {
      if(nextCity == curCity) continue;
      answer += memo(locations, nextCity, finish, fuel-abs(locations[nextCity] - locations[curCity]));
      answer %= MOD;
    }
    dp[curCity][fuel] = answer;
    return answer;
  }
public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    int cityLen = locations.size();
    dp.resize(cityLen, vector<int>(fuel + 1, -1));
    return memo(locations, start, finish, fuel);
  }
};

// Accepted
// 109/109 cases passed (275 ms)
// Your runtime beats 23.76 % of cpp submissions
// Your memory usage beats 27.62 % of cpp submissions (11.9 MB)
// @lc code=end

