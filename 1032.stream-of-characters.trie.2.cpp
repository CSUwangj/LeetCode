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
  char d[2001];
  int begin = 0;
  int end = 1;

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
    d[end] = letter - 'a';
    end = end == 2000 ? 0 : end + 1;
    if((end - begin + 2000) % 2001 > maxLength) begin += 1;
    if(begin == 2000) begin = 1;
    auto cur = &(trie[root]);
    for(int i = (end + 2000) % 2001; i != begin; i = (i + 2000) % 2001) {
      char c = d[i];
      if(!cur->next[c]) return false;
      else if(cur->begin & (1 << c)) return true;
      else cur = &(trie[cur->next[c]]);
    }
    return false;
  }
};

// Accepted
// 17/17 cases passed (160 ms)
// Your runtime beats 99.32 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (90.7 MB)
// @lc code=end
