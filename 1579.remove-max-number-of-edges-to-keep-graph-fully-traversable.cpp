/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
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
  bool addEdge(UnionSet &graph, const vector<int> &edge) {
    if(graph.find(edge[1] - 1) != graph.find(edge[2] - 1)) {
      graph.merge(edge[2] - 1, edge[1] - 1);
      return true;
    }
    return false;
  }
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    UnionSet alice(n), bob(n);
    sort(edges.begin(), edges.end(), greater<vector<int>>());

    int answer = 0;
    for(const auto &edge : edges) {
      if(edge[0] == 3) {
        bool result = !addEdge(alice, edge);
        result = !addEdge(bob, edge) && result;
        answer += result;
      } else if(edge[0] == 2) {
        answer += !addEdge(bob, edge);
      } else {
        answer += !addEdge(alice, edge);
      }
      // cout << edge << ' ' << answer << endl;
    }
    int ag0 = alice.find(0);
    int bg0 = bob.find(0);
    for(int i = 1; i < n; ++i) {
      // cout << ag0 << ' '<< alice.find(i) << endl;
      // cout << bg0 << ' ' << bob.find(i) << endl;
      if(alice.find(i) != ag0) return -1;
      if(bob.find(i) != bg0) return -1;
    }

    return answer;
  }
};

// Accepted
// 85/85 cases passed (868 ms)
// Your runtime beats 16.67 % of cpp submissions
// Your memory usage beats 50.72 % of cpp submissions (141 MB)
// @lc code=end

