/*
 * @lc app=leetcode id=882 lang=cpp
 *
 * [882] Reachable Nodes In Subdivided Graph
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int MAX = INT_MAX / 2;
class Solution {
  using pi = pair<int, int>;
  vector<vector<pi>> neighbors;
  vector<int> distance;
  void init(int n, vector<vector<int>>& edges) {
    neighbors.resize(n);
    distance.resize(n, MAX);

    for(auto &edge : edges) {
      neighbors[edge[0]].push_back({edge[1], edge[2] + 1});
      neighbors[edge[1]].push_back({edge[0], edge[2] + 1});
    }
  }
  void dijkstra() {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 0});

    while(pq.size()) {
      auto [moves, cur] = pq.top();
      pq.pop();
      if(distance[cur] != MAX) continue;
      distance[cur] = moves;
      for(auto [nxt, edge] : neighbors[cur]) {
        if(distance[nxt] != MAX) continue;
        pq.push({edge + moves, nxt});
      }
    }
  }
public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    init(n, edges);
    dijkstra();

    int answer = 0;
    for(auto &edge : edges) {
      if(distance[edge[0]] + edge[2] <= maxMoves \
      || distance[edge[1]] + edge[2] <= maxMoves \
      || 2 * maxMoves - distance[edge[0]] - distance[edge[1]] >= edge[2]) {
        answer += edge[2];
      } else {
        if(distance[edge[0]] < maxMoves) {
          answer += maxMoves - distance[edge[0]];
        }
        if(distance[edge[1]] < maxMoves) {
          answer += maxMoves - distance[edge[1]];
        }
      }
    }

    for(int i = 0; i < n; ++i) {
      answer += distance[i] <= maxMoves;
    }
    
    return answer;
  }
};

// Accepted
// 47/47 cases passed (137 ms)
// Your runtime beats 73.76 % of cpp submissions
// Your memory usage beats 91.4 % of cpp submissions (38.8 MB)
// @lc code=end

