/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
const int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  int rows;
  int cols;
  bool check(vector<vector<int>>& matrix, int row, int col) {
    int ok = 0;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols ||
         matrix[row][col] <= matrix[newRow][newCol]) {
        ok += 1;
      }
    }
    // cout << row << ' ' << col << ' ' << ok << endl;
    return ok == 4;
  }
  void dfs(vector<vector<int>>& matrix,
           vector<vector<int>> &LIP,
           int row,
           int col,
           int cur
  ) {
    if(cur <= LIP[row][col]) return;
    LIP[row][col] = cur;
    for(int i = 0; i < 4; ++i) {
      int newRow = row + moves[i][0];
      int newCol = col + moves[i][1];
      if(newRow >= rows || newRow < 0 || newCol >= cols || newCol < 0) continue;
      if(matrix[row][col] >= matrix[newRow][newCol]) continue;
      dfs(matrix, LIP, newRow, newCol, cur + 1);
    }
  }
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    rows = matrix.size();
    cols = matrix.front().size();
    vector<vector<int>> LIP(rows, vector<int>(cols));
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(check(matrix, i, j)) dfs(matrix, LIP, i, j, 1);
      }
    }
    int answer = 0;
    for(auto &row : LIP) {
      for(auto n : row) {
        // cout << n << ' ' ;
        answer = max(answer, n);
      }
      // cout << endl;
    }
    return answer;
  }
};

// Accepted
// 138/138 cases passed (185 ms)
// Your runtime beats 16.48 % of cpp submissions
// Your memory usage beats 41.9 % of cpp submissions (16.3 MB)
// @lc code=end

