/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
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
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    UnionSet us(isConnected.size());

    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i == j) continue;
        if(isConnected[i][j]) {
          us.merge(i, j);
        }
      }
    }

    set<int> st;
    for(int i = 0; i < n; ++i) {
      st.insert(us.find(i));
    }

    return st.size();
  }
};

// Accepted
// 113/113 cases passed (17 ms)
// Your runtime beats 97.38 % of cpp submissions
// Your memory usage beats 59.39 % of cpp submissions (13.9 MB)
// @lc code=end

