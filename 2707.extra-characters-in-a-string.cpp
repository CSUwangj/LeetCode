/*
 * @lc app=leetcode id=2707 lang=cpp
 *
 * [2707] Extra Characters in a String
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
  TrieNode *root = new TrieNode();
  int solve(const string &s, int position, vector<int> &memo) {
    if(position == s.length()) return 0;
    if(memo[position] != -1) return memo[position];
    int initPositon = position;
    int result = 1 + solve(s, position + 1, memo);
    TrieNode *current = root;
    while(position < s.length() && current->child[s[position] - 'a']) {
      current = current->child[s[position] - 'a'];
      position += 1;
      if(current->end) {
        result = min(result, solve(s, position, memo));
      }
    }
    return memo[initPositon] = result;
  }
public:
  int minExtraChar(string s, vector<string>& dictionary) {
    vector<int> memo(s.length(), -1);
    for(auto &word : dictionary) {
      insert(root, word);
    }
    return solve(s, 0, memo);
  }
};

// Accepted
// 103/103 cases passed (40 ms)
// Your runtime beats 99.84 % of cpp submissions
// Your memory usage beats 28.42 % of cpp submissions (105.78 MB)
// @lc code=end

