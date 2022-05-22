// Trie tree for lower case and with ending mark

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