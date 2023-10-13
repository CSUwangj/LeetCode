/*
 * @lc app=leetcode id=1489 lang=cpp
 *
 * [1489] Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree
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
  int findMST(
    const vector<vector<int>>& edges,
    int n,
    int ignore,
    int mustHave
  ) {
    UnionSet us(n);

    int weight = 0;
    if(mustHave != -1) {
      us.merge(edges[mustHave][0], edges[mustHave][1]);
      weight += edges[mustHave][2];
    }

    for(int i = 0; i < edges.size(); ++i) {
      if(i == ignore) continue;
      if(us.find(edges[i][0]) == us.find(edges[i][1])) continue;
      us.merge(edges[i][0], edges[i][1]);
      weight += edges[i][2];
    }

    for(int i = 0; i < n; ++i) {
      if(us.find(i) != us.find(0)) {
        weight = INT_MAX;
        continue;
      }
    }

    return weight;
  }
public:
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
    vector<int> critical, pseudoCritical;

    for(int i = 0; i < edges.size(); ++i) {
      edges[i].push_back(i);
    }
    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[2] < b[2];
    });

    int MSTWeight = findMST(edges, n, -1, -1);

    for(int i = 0; i < edges.size(); ++i) {
      if(MSTWeight < findMST(edges, n, i, -1)) {
        critical.push_back(edges[i][3]);
      } else if(MSTWeight == findMST(edges, n, -1, i)) {
        pseudoCritical.push_back(edges[i][3]);
      }
    }

    return {critical, pseudoCritical};
  }
};

// Accepted
// 66/66 cases passed (160 ms)
// Your runtime beats 58.42 % of cpp submissions
// Your memory usage beats 86.58 % of cpp submissions (14.8 MB)
// @lc code=end

