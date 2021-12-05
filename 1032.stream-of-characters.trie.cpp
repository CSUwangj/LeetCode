/*
 * @lc app=leetcode id=1032 lang=cpp
 *
 * [1032] Stream of Characters
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();

struct TrieNode {
  int begin;
  int next[26];
};

TrieNode trie[40001];
class StreamChecker {
  int root;
  int index;
  int maxLength = 0;
  deque<char> d;

  int useNext() {
    memset(trie + index, 0 , sizeof(TrieNode));
    return index++;
  }
public:
  StreamChecker(vector<string>& words) {
    index = 0;
    root = useNext();
    for(auto &word: words) {
      auto cur = &(trie[root]);
      for(int i = word.length() - 1; i >= 0; --i) {
        char c = word[i] - 'a';
        if(!cur->next[c]) {
          cur->next[c] = useNext();
        } 
        if(!i) {
          cur->begin |= (1 << c);
        }
        cur = &(trie[cur->next[c]]);
      }
      if(word.length() > maxLength) maxLength = word.length();
    }
  }
  
  bool query(char letter) {
    d.push_front(letter - 'a');
    if(d.size() > maxLength) d.pop_back();
    auto cur = &(trie[root]);
    for(auto i : d) {
      if(!cur->next[i]) return false;
      else if(cur->begin & (1 << i)) return true;
      else cur = &(trie[cur->next[i]]);
    }
    return false;
  }
};

// Accepted
// 17/17 cases passed (168 ms)
// Your runtime beats 99.1 % of cpp submissions
// Your memory usage beats 99.77 % of cpp submissions (90.9 MB)
// @lc code=end
