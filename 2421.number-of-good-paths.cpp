/*
 * @lc app=leetcode id=2421 lang=cpp
 *
 * [2421] Number of Good Paths
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

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
  vector<vector<int>> neighbors;
public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int len = vals.size();
    neighbors.resize(len);
    UnionSet us(len);

    map<int, vector<int>> nodes;
    for(int i = 0; i < len; ++i) {
      nodes[vals[i]].push_back(i);
    }
    for(const auto &edge : edges) {
      if(vals[edge[0]] >= vals[edge[1]]) {
        neighbors[edge[0]].push_back(edge[1]);
      }
      if(vals[edge[0]] <= vals[edge[1]]) {
        neighbors[edge[1]].push_back(edge[0]);
      }
    }

    int answer = len;
    for(const auto &[_val, nodes] : nodes) {
      for(auto node : nodes) {
        for(auto next : neighbors[node]) {
          us.merge(node, next);
        }
      }
      map<int, int> counts;
      for(auto node : nodes) {
        counts[us.find(node)] += 1;
      }
      for(const auto &[root, count] : counts) {
        answer += (count) * (count - 1) / 2;
      }
    }

    return answer;
  }
};

// Accepted
// 134/134 cases passed (627 ms)
// Your runtime beats 97.53 % of cpp submissions
// Your memory usage beats 82.68 % of cpp submissions (190.8 MB)
// @lc code=end

