/*
 * @lc app=leetcode id=1377 lang=cpp
 *
 * [1377] Frog Position After T Seconds
 */

// @lc code=start
class Solution {
public:
  double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    vector<vector<int>> neighbors(n + 1);
    vector<bool> vis(n + 1);
    vector<double> probability(n + 1);
    for(auto &edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }
    neighbors[1].push_back(1);
    queue<int> q;

    q.push(1);
    probability[1] = 1;
    for(int i = 0; i < t && q.size(); ++i) {
      int sz = q.size();
      for(int node = 0; node < sz; ++node) {
        int pos = q.front();
        q.pop();
        vis[pos] = true;
        if(neighbors[pos].size() == 1) {
          continue;
        }
        double prob = probability[pos] / (neighbors[pos].size() - 1);
        for(auto child : neighbors[pos]) {
          if(vis[child]) continue;
          q.push(child);
          probability[child] = prob;
        }
        probability[pos] = 0;
      }
    }

    return probability[target];
  }
};
// @lc code=end

