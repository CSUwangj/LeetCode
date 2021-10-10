/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
struct TrieNode {
  bool end = false;
  TrieNode *child[128] = {};
};
void insert(TrieNode *root, string word) {
  TrieNode *cur = root;
  for(auto c : word) {
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
    root = root->child[board[row][col]];
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
  bool exist(vector<vector<char>>& board, string word) {
    TrieNode *root = new TrieNode();
    rows = board.size();
    cols = board.front().size();
    vis.resize(rows, vector<bool>(cols));
    insert(root, word);
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        solve(board, root, i, j);
      }
    }
    return words.size();
  }
};

// Accepted
// 57/57 cases passed (312 ms)
// Your runtime beats 62.95 % of cpp submissions
// Your memory usage beats 5.08 % of cpp submissions (8.2 MB)
// @lc code=end

