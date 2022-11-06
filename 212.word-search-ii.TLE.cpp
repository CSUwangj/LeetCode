/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
struct TrieNode {
  bool end = false;
  TrieNode *child[26] = {};
};
void insert(TrieNode *root, string &word) {
  TrieNode *cur = root;
  for(auto c : word) {
    c = c - 'a';
    if(!cur->child[c]) {
      cur->child[c] = new TrieNode();
    }
    cur = cur->child[c];
  }
  cur->end = true;
}
constexpr int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  vector<vector<bool>> vis;
  vector<string> words;
  string current;
  int rows;
  int cols;
  void solve(vector<vector<char>>& board, TrieNode *root, int row, int col) {
    root = root->child[board[row][col] - 'a'];
    vis[row][col] = true;
    current.push_back(board[row][col]);
    if(root) {
      if(root->end) words.push_back(current);
      for(int i = 0; i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(vis[newRow][newCol]) continue;
        solve(board, root, newRow, newCol);
      }
    }
    vis[row][col] = false;
    current.pop_back();
  }
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& w) {
    TrieNode *root = new TrieNode();
    rows = board.size();
    cols = board.front().size();
    vis.resize(rows, vector<bool>(cols));
    for(auto &word : w) {
      insert(root, word);
    }
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        solve(board, root, i, j);
      }
    }
    sort(words.begin(), words.end());
    words.resize(unique(words.begin(), words.end()) - words.begin());
    return words;
  }
};

// Time Limit Exceeded
// 63/64 cases passed (N/A)
// @lc code=end

