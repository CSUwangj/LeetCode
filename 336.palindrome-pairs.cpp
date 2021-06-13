/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
struct TrieNode {
  TrieNode *children[26] = {};
  int index = -1;
  vector<int> palinIndex;
};

inline bool isPalindrome(const string &word, int start, int end) {
  while(start < end) {
    if(word[start] != word[end]) return false;
    start += 1;
    end -= 1;
  }
  return true;
}

void addWord(TrieNode *root, const string &word, int index) {
  int len = word.size();
  auto cur = root;
  for(int i = len - 1; i >= 0; i--) {
    int ch = word[i] - 'a';
    if(!(cur->children[ch])) cur->children[ch] = new TrieNode();
    if(isPalindrome(word, 0, i)) cur->palinIndex.push_back(index);

    cur = cur->children[ch];
  }
  cur->palinIndex.push_back(index);
  cur->index = index;
}

void search(TrieNode *root, vector<string> &words, int index, vector<vector<int>> &answer) {
  auto cur = root;
  auto curWord = words[index];
  int len = curWord.length();

  for(int i = 0; i < len; i++) {
    if(cur->index != -1 && cur->index != index && isPalindrome(curWord, i, len - 1)) {
      answer.push_back({index, cur->index});
    }
    cur = cur->children[curWord[i] - 'a'];
    if(!cur) return;
  }
  for(auto idxPalin : cur->palinIndex) {
    if(idxPalin == index) continue;
    answer.push_back({index, idxPalin});
  }
}

class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    auto root = new TrieNode();
    int len = words.size();
    vector<vector<int>> answer;

    for(int i = 0; i < words.size(); ++i) addWord(root, words[i], i);
    for(int i = 0; i < words.size(); ++i) search(root, words, i, answer);

    return answer;
  }
};
// @lc code=end

