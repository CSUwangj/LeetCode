/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
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
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int len = s.length();
    UnionSet us(s.length());
    for(const auto &pair : pairs) {
      us.merge(pair[0], pair[1]);
    }
    unordered_map<int, vector<int>> indice;
    unordered_map<int, string> chars;
    for(int i = 0; i < len; ++i) {
      int parent = us.find(i);
      indice[parent].push_back(i);
      chars[parent].push_back(s[i]);
    }
    for(auto &[parent, s] : chars) {
      sort(s.begin(), s.end());
    }
    string answer(len, '\x00');
    for(const auto &[parent, index]: indice) {
      for(int i = 0; i < index.size(); ++i) {
        answer[index[i]] = chars[parent][i];
      }
    }
    return move(answer);
  }
};

// Accepted
// 36/36 cases passed (176 ms)
// Your runtime beats 85.32 % of cpp submissions
// Your memory usage beats 73.82 % of cpp submissions (49.6 MB)
// @lc code=end