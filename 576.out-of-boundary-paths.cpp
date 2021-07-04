/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
const int SZ = 50;
const int MOD = 1e9 + 7;
int path[2][SZ][SZ];
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    memset(path[0], 0, sizeof(path[0]));
    path[0][startRow][startColumn] = 1;
    int result = 0;
    for(int cnt = 0; cnt < maxMove; cnt++) {
      int parity = cnt & 1;
      memset(path[!parity], 0, sizeof(path[0]));
      for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
          // cout << path[parity][i][j] << ' ' ;
          for(int c = 0; c < 4; ++c) {
            int newRow = i + moves[c][0];
            int newCol = j + moves[c][1];
            if(newRow < 0 || newCol < 0 || newRow >= m || newCol >= n) continue;
            path[!parity][newRow][newCol] += path[parity][i][j];
            path[!parity][newRow][newCol] %= MOD;
          }
        }
        // cout << endl;
      }
      // cout << endl;
      for(int i = 0; i < m; ++i) {
        result += path[parity][i][0];
        result %= MOD;
        result += path[parity][i][n - 1];
        result %= MOD;
      }
      for(int i = 0; i < n; ++i) {
        result += path[parity][0][i];
        result %= MOD;
        result += path[parity][m - 1][i];
        result %= MOD;
      }
    }
    return result;
  }
};
// @lc code=end

