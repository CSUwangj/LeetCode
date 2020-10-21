#include <bits/stdc++.h>
#define LL long long
#define mk(a, b) make_pair(a, b)
#define ULL unsigned long long
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x) & (-x))
using namespace std;

class Solution {
  vector<int> rows = vector<int>(9);
  vector<int> cols = vector<int>(9);
  vector<int> squares = vector<int>(9);
  int row(int x){return x / 9;};
  int col(int x){return x % 9;};
  int square(int x) { return x / 9 / 3 * 3 + x % 9 / 3; }

  void init(vector<vector<char>>& board) {
    for(int i = 0; i < 81; ++i) {
      int r = row(i), c = col(i), s = square(i);
      if((board[r][c]) == '.') continue;
      rows[r] |= (1 << (board[r][c] - '0'));
      cols[c] |= (1 << (board[r][c] - '0'));
      squares[s] |= (1 << (board[r][c] - '0'));
    }
  }

  bool dfs(int pos, vector<vector<char>>& board) {
    if(pos == 81) return true;
    int r = row(pos), c = col(pos), s = square(pos);
    if(board[r][c] != '.') return dfs(pos + 1, board);
    for(int i = 1; i < 10; ++i) {
      if(!(rows[r]&(1 << i)) && !(cols[c]&(1 << i)) && !(squares[s]&(1 << i))) {
        rows[r] |= (1 << i);
        cols[c] |= (1 << i);
        squares[s] |= (1 << i);
        if(dfs(pos+1, board)) {
          board[r][c] = i+'0';
          return true;
        }
        rows[r] ^= (1 << i);
        cols[c] ^= (1 << i);
        squares[s] ^= (1 << i);
      }
    }
    return false;
  }
 public:
  void solveSudoku(vector<vector<char>>& board) {
    init(board);
    dfs(0, board);
  }
};

int main() {
  vector<vector<vector<char>>> data = {
      {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}}};
  for (auto& data : data) {
    auto sol = Solution();
    for(auto &i : data) {
      for(auto &j : i) {
        cout << j << " ";
      }
      cout << endl;
    }
    sol.solveSudoku(data);
    for(auto &i : data) {
      for(auto &j : i) {
        cout << j << " ";
      }
      cout << endl;
    }
  }
  return 0;
}