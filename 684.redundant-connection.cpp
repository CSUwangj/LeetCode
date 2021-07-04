/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution {
  int parent[1000];

  int find(int x) {
    if(x != parent[x]) parent[x] = find(parent[x]);
    return parent[x];
  }
  
  void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    parent[px] = py;
  }

  void init() {
    for(int i = 0; i < 1000; i++) parent[i] = i;
  }
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    init();
    for(auto &edge : edges) {
      int x = edge[0] - 1;
      int y = edge[1] - 1;
      int px = find(x);
      int py = find(y);
      if(px != py) merge(x, y);
      else return edge;
    }
    return {-1, -1};
  }
};
// @lc code=end

