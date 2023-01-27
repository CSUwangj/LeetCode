/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
struct TrieNode {
  TrieNode* children[26];
  int count = 0;
  bool end = false;
};
void insert(TrieNode *root, const string &word) {
  TrieNode *cur = root;
  for(auto c : word) {
    c -= 'a';
    if(!(cur->children[c])) {
      cur->children[c] = new TrieNode();
    }
    cur = cur->children[c];
    cur->count += 1;
  }
  cur->end = true;
}
void remove(TrieNode *root, const string &word) {
  TrieNode *cur = root;
  vector<TrieNode*> path;
  for(auto c : word) {
    path.push_back(cur);
    c -= 'a';
    cur = cur->children[c];
  }
  cur->end = false;
  TrieNode *prev;
  for(auto it = word.rbegin(); it != word.rend(); ++it) {
    prev = cur;
    cur = path.back();
    path.pop_back();
    int c = *it - 'a';
    prev->count -= 1;
    if(prev->count == 0) {
      // memory leak, but delete will slow down the code
      // delete cur->children[c];
      cur->children[c] = nullptr;
    }
  }
}
class Solution {
  unordered_map<string, bool> valid;
  TrieNode *root;
  bool check(const string &word, int pos) {
    if(pos && valid.count(word.substr(pos))) {
      return valid[word.substr(pos)];
    }
    TrieNode *cur = root;
    for(int i = pos; i < word.length(); ++i) {
      int c = word[i] - 'a';
      if(!(cur->children[c])) return valid[word] = false;
      cur = cur->children[c];
      if(cur->end && check(word, i + 1)) return valid[word] = true;
    }
    
    return pos && (valid[word] = cur->end);
  }
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    int minLen = INT_MAX;
    set<string> basicWords;
    root = new TrieNode();
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
      return a.length() < b.length();
    });

    for(const auto &word : words) {
      minLen = min<int>(minLen, word.length());
      valid[word] = true;
      insert(root, word);
    }
    
    vector<string> answer;
    for(const auto &word: words) {
      if(word.length() < minLen * 2) continue;
      if(check(word, 0)) {
        answer.push_back(word);
        remove(root, word);
      }
      valid[word] = true;
    }

    return answer;
  }
};

// Accepted
// 42/42 cases passed (211 ms)
// Your runtime beats 82.87 % of cpp submissions
// Your memory usage beats 11.55 % of cpp submissions (239 MB)
// @lc code=end

