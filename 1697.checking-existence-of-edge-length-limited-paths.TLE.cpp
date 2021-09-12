/*
 * @lc app=leetcode id=1697 lang=cpp
 *
 * [1697] Checking Existence of Edge Length Limited Paths
 */

// @lc code=start
class Solution {
  using pi = pair<int, int>;
  int n;
  vector<unordered_map<int, int>> neighbors;
  vector<unordered_map<int, int>> distance;
  void init(int n, vector<vector<int>>& edgeList) {
    this-> n = n;
    neighbors.resize(n);
    distance.resize(n);
    for(auto &edge : edgeList) {
      if(edge[0] > edge[1]) {
        swap(edge[0], edge[1]);
      }
    }
    sort(edgeList.begin(), edgeList.end());
    int len = edgeList.size();
    for(int i = 0; i < len; ++i) {
      if(i && edgeList[i][0] == edgeList[i - 1][0] && edgeList[i][1] == edgeList[i - 1][1]) continue;
      neighbors[edgeList[i][0]][edgeList[i][1]] = edgeList[i][2];
      neighbors[edgeList[i][1]][edgeList[i][0]] = edgeList[i][2];
    }
  }
  void solveOneSource(int start) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<bool> vis(n);
    pq.push({0, start});
    while(pq.size()) {
      auto [dis, pos] = pq.top();
      pq.pop();
      if(vis[pos]) continue;
      distance[start][pos] = dis;
      distance[pos][start] = dis;
      vis[pos] = true;
      for(auto &[nxt, edge] : neighbors[pos]) {
        if(vis[nxt]) continue;
        pq.push({max(dis, edge), nxt});
      }
    }
  }
public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    init(n, edgeList);
    vector<bool> answer;
    for(auto &query : queries) {
      if(!distance[query[0]].count(query[1])) {
        solveOneSource(query[0]);
      }
      // cout << distance[query[0]][query[1]] << endl;
      answer.push_back(distance[query[0]][query[1]] < query[2]);
    }

    return answer;
  }
};
// @lc code=end

