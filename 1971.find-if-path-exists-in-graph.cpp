/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
struct UnionSet {
  vector<int> parent;
public:
  UnionSet(int size): parent(size) {
    for(int i = 0; i < size; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
  }
};
class Solution {
public:
  bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    UnionSet us(n);
    for(const auto &edge : edges) {
      us.merge(edge[0], edge[1]);
    }
    return us.find(source) == us.find(destination);
  }
};

// Accepted
// 27/27 cases passed (424 ms)
// Your runtime beats 98.64 % of cpp submissions
// Your memory usage beats 97.67 % of cpp submissions (111 MB)
// @lc code=end

