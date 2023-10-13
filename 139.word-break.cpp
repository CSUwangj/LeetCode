/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
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
  vector<bool> visit;
  bool solve(const string &s, int pos) {
    TrieNode *cur = root;
    if(len == pos) return true;
    if(visit[pos]) return false;
    int start = pos;
    while(pos < len) {
      if(!cur->child[s[pos] - 'a']) {
        visit[start] = true;
        return false;
      }
      cur = cur->child[s[pos] - 'a'];
      pos += 1;
      if(cur->end && solve(s, pos)) return true;
    }
    visit[pos] = true;
    return false;
  }
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    root = new TrieNode();
    len = s.length();
    visit.resize(len);
    for(const auto &word : wordDict) {
      insert(root, word);
    }
    return solve(s, 0);
  }
};

// Accepted
// 46/46 cases passed (3 ms)
// Your runtime beats 91.38 % of cpp submissions
// Your memory usage beats 54.73 % of cpp submissions (10.1 MB)
// @lc code=end
