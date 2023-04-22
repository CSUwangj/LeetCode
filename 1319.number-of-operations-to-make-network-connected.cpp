/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
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
public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size() < n - 1) return -1;
    UnionSet us(n);

    for(const auto &connection : connections) {
      us.merge(connection[0], connection[1]);
    }

    set<int> group;
    for(int i = 0; i < n; ++i) {
      group.insert(us.find(i));
    }
    return group.size() - 1;
  }
};

// Accepted
// 36/36 cases passed (108 ms)
// Your runtime beats 94.31 % of cpp submissions
// Your memory usage beats 82.31 % of cpp submissions (39.7 MB)
// @lc code=end

