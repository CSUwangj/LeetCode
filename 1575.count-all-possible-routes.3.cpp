/*
 * @lc app=leetcode id=1575 lang=cpp
 *
 * [1575] Count All Possible Routes
 */

// @lc code=start
sp
class Solution {
  const int MOD = 1e9 + 7;
  using pi = pair<int, int>;
public:
  int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    int len = locations.size();
    vector<vector<int>> routes(len, vector<int>(fuel + 1));
    routes[start][0] = 1;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, start});
    while(q.size()) {
      auto [usedFuel, position] = q.top();
      q.pop();
      for(int i = 0; i < len; ++i) {
        if(i == position) continue;
        int newFuel = usedFuel + abs(locations[i] - locations[position]);
        if(newFuel > fuel) continue;
        if(!routes[i][newFuel]) q.push({newFuel, i});
        routes[i][newFuel] += routes[position][usedFuel];
        routes[i][newFuel] %= MOD;
      }
    }

    int answer = 0;
    for(const auto &route : routes[finish]) {
      answer += route;
      answer %= MOD;
    }
    return answer;
  }
};

// Accepted
// 109/109 cases passed (1154 ms)
// Your runtime beats 5.25 % of cpp submissions
// Your memory usage beats 5.25 % of cpp submissions (19.6 MB)
// @lc code=end

