/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<vector<int>> neighbors[2];
    neighbors[0].resize(n);
    neighbors[1].resize(n);
    for(const auto &redEdge : redEdges) {
      neighbors[0][redEdge[0]].push_back(redEdge[1]);
    }
    for(const auto &blueEdge : blueEdges) {
      neighbors[1][blueEdge[0]].push_back(blueEdge[1]);
    }
    vector<int> distance[2];
    distance[0].resize(n, INT_MAX);
    distance[1].resize(n, INT_MAX);
    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({0, 1});
    distance[0][0] = 0;
    distance[1][0] = 0;

    int current = 0;
    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto [pos, color] = q.front();
        q.pop();
        for(auto next : neighbors[!color][pos]) {
          if(distance[!color][next] != INT_MAX) continue;
          distance[!color][next] = current + 1;
          q.push({next, !color});
        }
      }
      current += 1;
    }

    for(int i = 0; i < n; ++i) {
      distance[0][i] = min(distance[0][i], distance[1][i]);
      if(distance[0][i] == INT_MAX) {
        distance[0][i] = -1;
      }
    }

    return distance[0];
  }
};

// Accepted
// 90/90 cases passed (15 ms)
// Your runtime beats 95.27 % of cpp submissions
// Your memory usage beats 89.64 % of cpp submissions (14.7 MB)
// @lc code=end

