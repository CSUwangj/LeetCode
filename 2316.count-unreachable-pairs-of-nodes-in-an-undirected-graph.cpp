/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
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
  long long countPairs(int n, vector<vector<int>>& edges) {
    UnionSet us(n);
    for(const auto &edge : edges) {
      us.merge(edge[0], edge[1]);
    }

    map<int, int> group;
    for(int i = 0; i < n; ++i) {
      group[us.find(i)] += 1;
    }

    vector<int> counts;
    counts.reserve(group.size());
    for(const auto &[_, count] : group) {
      counts.push_back(count);
    }
    long long answer = 0;
    for(int i = 1; i < counts.size(); ++i) {
      answer += 1LL * counts[i] * counts[i - 1];
      counts[i] += counts[i - 1];
    }

    return answer;
  }
};

// Accepted
// 66/66 cases passed (497 ms)
// Your runtime beats 95.88 % of cpp submissions
// Your memory usage beats 91.62 % of cpp submissions (150.5 MB)
// @lc code=end

