/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
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
  bool equationsPossible(vector<string>& equations) {
    UnionSet us(26);
    for(const auto &equation : equations) {
      if(equation[1] == '=') {
        us.merge(equation[0] - 'a', equation[3] - 'a');
      }
    }

    for(const auto &equation : equations) {
      if(equation[1] == '!' && us.find(equation[0] - 'a') == us.find(equation[3] - 'a')) {
        return false;
      }
    }
    return true;
  }
};

// Accepted
// 181/181 cases passed (19 ms)
// Your runtime beats 16.42 % of cpp submissions
// Your memory usage beats 44.49 % of cpp submissions (11.4 MB)
// @lc code=end

