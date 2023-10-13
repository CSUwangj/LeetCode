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
    int pos1 = -1;
    int pos = 0;
    while(pos < len && a[pos] == b[pos]) {
      pos += 1;
    }
    if(pos == len) return true;
    pos1 = pos;
    pos += 1;
    while(pos < len && a[pos] == b[pos]) {
      pos += 1;
    }
    if(pos == len) return false;
    if(a[pos1] != b[pos] || b[pos1] != a[pos]) return false;
    pos += 1;
    while(pos < len && a[pos] == b[pos]) {
      pos += 1;
    }
    return pos == len;
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
// 77/77 cases passed (23 ms)
// Your runtime beats 92.7 % of cpp submissions
// Your memory usage beats 58.73 % of cpp submissions (10.2 MB)
// @lc code=end

