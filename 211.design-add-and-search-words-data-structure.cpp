/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct TrieNode {
  bool end = false;
  TrieNode *children[26] = {};
};

void deleteTrie(TrieNode *root) {
  if(!root) return;
  for(auto child : root->children) {
    deleteTrie(child);
  }
  delete root;
}

class WordDictionary {
  TrieNode *root;

  bool helper(const string &word, TrieNode *cur, int pos = 0) {
    int len = word.length();
    for(int i = pos; i < len; ++i) {
      if(word[i] != '.') {
        if(!cur->children[word[i] - 'a']) return false;
        cur = cur->children[word[i] - 'a'];
      } else {
        for(auto child : cur->children) {
          if(child && helper(word, child, i + 1)) return true;
        }
        return false;
      }
    }
    return cur->end;
  }
public:
  WordDictionary() {
    root = new TrieNode();
  }

  ~WordDictionary() {
    deleteTrie(root);
  }
  
  void addWord(string word) {
    TrieNode *cur = root;
    for(auto c : word) {
      c -= 'a';
      if(!cur->children[c]) {
        cur->children[c] = new TrieNode();
      }
      cur = cur->children[c];
    }
    cur->end = true;
  }
  
  bool search(string word) {
    return helper(word, root);
  }
};

// Accepted
// 29/29 cases passed (1168 ms)
// Your runtime beats 70.82 % of cpp submissions
// Your memory usage beats 86.5 % of cpp submissions (465.2 MB)
