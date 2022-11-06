/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
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
  int count = 0;
  TrieNode *child[26] = {};
};
void insert(TrieNode *root, const string &word) {
  TrieNode *cur = root;
  for(auto c : word) {
    c = c - 'a';
    if(!cur->child[c]) {
      cur->child[c] = new TrieNode();
    }
    cur = cur->child[c];
    cur->count += 1;
  }
  cur->end = true;
}
int prune(TrieNode *root, const string &word) {
  TrieNode *cur = root;
  int backStep = word.length();
  // cout << word << endl;
  for(auto c : word) {
    // cout << c ;
    c = c - 'a';
    // cout << cur->child[c]->count;
    if(cur->child[c]->count == 1) {
      // delete then RE, fuck u leetcode
      cur->child[c] = nullptr;
      break;
    } else {
      backStep -= 1;
      cur = cur->child[c];
      cur->count -= 1;
    }
  }
  if(!backStep) cur->end = false;
  // cout << endl << backStep << endl;
  return backStep;
}
constexpr int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  vector<vector<bool>> vis;
  vector<string> words;
  string current;
  int rows;
  int cols;
  TrieNode *root = new TrieNode();
  void solve(const vector<vector<char>>& board, TrieNode *currentNode, int row, int col, int &backStep) {
    currentNode = currentNode->child[board[row][col] - 'a'];
    vis[row][col] = true;
    current.push_back(board[row][col]);
    if(currentNode) {
      if(currentNode->end) {
        words.push_back(current);
        backStep = prune(root, current);
      }
      for(int i = 0; !backStep && i < 4; ++i) {
        int newRow = row + moves[i][0];
        int newCol = col + moves[i][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(vis[newRow][newCol]) continue;
        solve(board, currentNode, newRow, newCol, backStep);
      }
    }
    if(backStep) {
      backStep -= 1;
    }
    vis[row][col] = false;
    current.pop_back();
  }
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& w) {
    rows = board.size();
    cols = board.front().size();
    vis.resize(rows, vector<bool>(cols));
    for(auto &word : w) {
      insert(root, word);
    }
    int backStep = 0;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        solve(board, root, i, j, backStep);
      }
    }
    return words;
  }
};

// Accepted
// 64/64 cases passed (227 ms)
// Your runtime beats 95.83 % of cpp submissions
// Your memory usage beats 35.69 % of cpp submissions (15.3 MB)
// @lc code=end

