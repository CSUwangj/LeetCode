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
constexpr int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  vector<vector<bool>> vis;
  int rows;
  int cols;
  bool find(vector<vector<char>>& board, int row, int col, string &word, int rest) {
    if(row < 0 || col < 0 || row >= rows || col >= cols) return false;
    if(word[rest] != board[row][col]) return false;
    if(!rest) return true;
    vis[row][col] = true;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
      if(vis[newRow][newCol]) continue;
      if(find(board, newRow, newCol, word, rest - 1)) {
        vis[row][col] = false;
        return true;
      }
    }
    vis[row][col] = false;
    return false;
  }
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& w) {
    rows = board.size();
    cols = board.front().size();
    vis.resize(rows, vector<bool>(cols));
    vector<string> answer;
    unordered_map<char, vector<pair<int, int>>> pos;
    for(auto &word : w) {
      pos[word.back()].clear();
    }
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(pos.count(board[i][j])) {
          pos[board[i][j]].push_back({i, j});
        }
      }
    }
    for(auto &word : w) {
      for(auto [row, col] : pos[word.back()]) {
        if(find(board, row, col, word, word.length() - 1)) {
          answer.push_back(word);
          break;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 51/51 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.61 % of cpp submissions (9.3 MB)
// @lc code=end

