/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat.front().size();
    vector<vector<bool>> vis(rows, vector<bool>(cols));
    queue<pair<int, int>> q;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(!mat[i][j]) {
          vis[i][j] = true;
          q.push({i, j});
        }
      }
    }
    int cnt = 1;
    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto [row, col] = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i) {
          int newRow = row + moves[i][0];
          int newCol = col + moves[i][1];
          if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
          if(vis[newRow][newCol]) continue;
          // cout << newRow << ' ' << newCol << ' ' << cnt << endl;
          vis[newRow][newCol] = true;
          mat[newRow][newCol] = cnt;
          q.push({newRow, newCol});
        }
      }
      cnt += 1;
    }
    return mat;
  }
};

// Accepted
// 50/50 cases passed (61 ms)
// Your runtime beats 92.14 % of cpp submissions
// Your memory usage beats 68.82 % of cpp submissions (32.1 MB)
// @lc code=end

