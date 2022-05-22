/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
struct TrieNode {
  bool end = false;
  TrieNode *child[26] = {};
};
void insert(TrieNode *root, const string &word) {
  TrieNode *cur = root;
  for(auto c : word) {
    if(!cur->child[c - 'a']) cur->child[c - 'a'] = new TrieNode();
    cur = cur->child[c - 'a'];
  }
  cur->end = true;
}
class Solution {
  TrieNode *root;
  int len;
  vector<vector<string>> cache;
  vector<bool> visit;
  void solve(
    const string &s,
    int pos
  ) {
    TrieNode *cur = root;
    if(len == pos) return;
    if(visit[pos]) return;
    int start = pos;
    while(pos < len) {
      if(!cur->child[s[pos] - 'a']) {
        visit[start] = true;
        return;
      }
      cur = cur->child[s[pos] - 'a'];
      pos += 1;
      if(cur->end) {
        solve(s, pos);
        for(const auto &rest : cache[pos]) {
          string result = s.substr(start, pos - start);
          if(rest.size()) {
            result = result + " " + rest;
          }
          cache[start].emplace_back(move(result));
        }
      }
    }
    visit[start] = true;
  }
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    root = new TrieNode();
    len = s.length();
    visit.resize(len + 1);
    cache.resize(len + 1);
    cache[len].push_back("");
    for(const auto &word : wordDict) {
      insert(root, word);
    }
    solve(s, 0);
    return cache[0];
  }
};

// Accepted
// 26/26 cases passed (2 ms)
// Your runtime beats 47.63 % of cpp submissions
// Your memory usage beats 27.1 % of cpp submissions (7.5 MB)
// @lc code=end
