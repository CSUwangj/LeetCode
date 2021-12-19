/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int par[20000];
class Solution {
  vector<vector<int>> neighbors;
  void init(int n, vector<vector<int>> &edges) {
    neighbors.resize(n);
    for(auto &edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }
  }

  pair<int, int> bfs() {
    queue<pair<int, int>> q;
    q.push({-1, 0});
    int oneEnd;
    while(q.size()) {
      auto [parent, cur] = q.front();
      q.pop();
      // cout << parent << ' ' << cur << endl;
      oneEnd = cur;
      for(auto next : neighbors[cur]) {
        if(next == parent) continue;
        q.push({cur, next});
      }
    }
    int len = 0;
    q.push({-1, oneEnd});
    while(q.size()) {
      len += 1;
      int curSize = q.size();
      for(int _ = 0; _ < curSize; ++_) {
        auto [parent, cur] = q.front();
        q.pop();
        par[cur] = parent;
        oneEnd = cur;
        for(auto next : neighbors[cur]) {
          if(next == parent) continue;
          q.push({cur, next});
        }
      }
    }
    return {len, oneEnd};
  }
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    init(n, edges);
    auto [len, end] = bfs();
    int target = (len - 1) / 2;
    for(int i = 0; i < target; ++i) {
      end = par[end];
    }
    if (len & 1) return {end};
    return {end, par[end]};
  }
};

// Accepted
// 68/68 cases passed (52 ms)
// Your runtime beats 98.84 % of cpp submissions
// Your memory usage beats 69.44 % of cpp submissions (27.5 MB)
// @lc code=end
