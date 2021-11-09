/*
 * @lc app=leetcode id=1178 lang=cpp
 *
 * [1178] Number of Valid Words for Each Puzzle
 */

// @lc code=start
struct TrieNode {
  int count = 0;
  TrieNode *child[26] = {};
};
void insert(TrieNode *root, const string &word) {
  TrieNode *cur = root;
  for(auto c : word) {
    c -= 'a';
    if(!cur->child[c]) {
      cur->child[c] = new TrieNode();
    }
    cur = cur->child[c];
  }
  cur->count += 1;
}
class Solution {
  int dfs(TrieNode *root, bool hasFirst, const string &puzzle/*, int level */) {
    int total = hasFirst ? root->count : 0;
    // cout << puzzle << level << ' ' << total << endl;
    for(auto c : puzzle) {
      int i = c - 'a';
      if(root->child[i]) {
        total += dfs(root->child[i], hasFirst || c == puzzle.front(), puzzle/*, level + 1 */);
      }
    }
    // cout << puzzle << level << ' ' << total << endl;
    return total;
  }
public:
  vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    TrieNode *root = new TrieNode();
    for(auto &word : words) {
      sort(word.begin(), word.end());
      word.erase(unique(word.begin(), word.end()), word.end());
      if(word.size() > 7) continue;
      insert(root, word);
    }

    vector<int> answer;
    answer.reserve(puzzles.size());
    for(const auto &puzzle : puzzles) {
      answer.push_back(dfs(root, false, puzzle/*, 0 */));
    }

    return answer;
  }
};

// Accepted
// 10/10 cases passed (208 ms)
// Your runtime beats 70.95 % of cpp submissions
// Your memory usage beats 30.95 % of cpp submissions (73.4 MB)
// @lc code=end

