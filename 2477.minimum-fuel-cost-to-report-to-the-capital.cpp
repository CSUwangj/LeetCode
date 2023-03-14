/*
 * @lc app=leetcode id=2477 lang=cpp
 *
 * [2477] Minimum Fuel Cost to Report to the Capital
 */

// @lc code=start
class Solution {
  long long answer = 0;
  long long dfs(
    int current,
    int parrent,
    int seats,
    vector<vector<int>> &neighbors
  ) {
    int rep = 1;
    for(const auto next : neighbors[current]) {
      if(next == parrent) continue;
      rep += dfs(next, current, seats, neighbors);
    }
    if(current) {
      answer += (rep + seats - 1) / seats;
    }
    return rep;
  }
public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    if(roads.empty()) return 0;
    vector<vector<int>> neighbors(roads.size() + 1);
    for(const auto &road : roads) {
      neighbors[road[0]].push_back(road[1]);
      neighbors[road[1]].push_back(road[0]);
    }

    dfs(0, -1, seats, neighbors);
    return answer;
  }
};

// Accepted
// 131/131 cases passed (557 ms)
// Your runtime beats 98.46 % of cpp submissions
// Your memory usage beats 77.66 % of cpp submissions (191.4 MB)
// @lc code=end

