/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
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
  int len;
  bool isSimilar(const string &a, const string &b) {
    int diff = 0;
    for(int i = 0; i < len; ++i) {
      diff += a[i] != b[i];
    }
    return diff == 0 || diff == 2;
  }
public:
  int numSimilarGroups(vector<string>& strs) {
    UnionSet us(strs.size());
    len = strs.front().length();

    int answer = strs.size();
    for(int i = 0; i < strs.size() - 1; ++i) {
      for(int j = i + 1; j < strs.size(); ++j) {
        if(isSimilar(strs[i], strs[j]) && us.find(i) != us.find(j)) {
          us.merge(i, j);
          answer -= 1;
        }
      }
    }

    return answer;
  }
};

// Accepted
// 77/77 cases passed (143 ms)
// Your runtime beats 57.78 % of cpp submissions
// Your memory usage beats 76.83 % of cpp submissions (10.1 MB)
// @lc code=end

