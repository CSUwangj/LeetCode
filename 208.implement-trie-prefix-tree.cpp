/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct TrieNode {
  bool isEnd = false;
  TrieNode *nodes[26] = {};
  ~TrieNode() {
    for(auto node : nodes) {
      delete node;
    }
  }
};
class Trie {
  TrieNode *root;
public:
    /** Initialize your data structure here. */
  Trie() {
    root = new TrieNode();
  }
  
  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode *cur = root;
    for(auto c : word) {
      if(cur->nodes[c - 'a'] == nullptr) {
        cur->nodes[c - 'a'] = new TrieNode();
      }
      cur = cur->nodes[c - 'a'];
    }
    cur->isEnd = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode *cur = root;
    for(auto c : word) {
      if(cur->nodes[c - 'a'] == nullptr) return false;
      cur = cur->nodes[c - 'a'];
    }
    return cur->isEnd;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    TrieNode *cur = root;
    for(auto c : prefix) {
      if(cur->nodes[c - 'a'] == nullptr) return false;
      cur = cur->nodes[c - 'a'];
    }
    return true;
  }
};

// Accepted
// 15/15 cases passed (40 ms)
// Your runtime beats 99.23 % of cpp submissions
// Your memory usage beats 73.15 % of cpp submissions (44.9 MB)
// @lc code=end

