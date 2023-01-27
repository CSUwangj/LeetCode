/*
 * @lc app=leetcode id=1061 lang=cpp
 *
 * [1061] Lexicographically Smallest Equivalent String
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
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    UnionSet us(26);
    int len = s1.length();
    for(int i = 0; i < len; ++i) {
      us.merge(s1[i] - 'a', s2[i] - 'a');
    }
    vector<char> mp(26);
    for(int i = 0; i < 26; ++i) {
      for(int j = 0; j < 26; ++j) {
        if(us.find(j) != us.find(i)) continue;
        mp[i] = j;
        break;
      }
    }
    for(auto &c : baseStr) {
      c = mp[c - 'a'] + 'a';
    }
    return baseStr;
  }
};

// Accepted
// 181/181 cases passed (3 ms)
// Your runtime beats 79.82 % of cpp submissions
// Your memory usage beats 60.55 % of cpp submissions (6.5 MB)
// @lc code=end

