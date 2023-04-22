/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  const int MOVES[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
  int closedIsland(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int rows = grid.size();
    int cols = grid.front().size();
    vector<vector<bool>> visit(rows, vector<bool>(cols));

    int answer = 0;
    for(int r = 0; r < rows; ++r) {
      for(int c = 0; c < cols; ++c) {
        if(grid[r][c] || visit[r][c]) {
          visit[r][c] = true;
          continue;
        }
        q.push({r, c});
        visit[r][c] = true;
        bool border = false;
        while(q.size()) {
          auto [row, col] = q.front();
          q.pop();
          if(!row || !col || row == rows - 1 || col == cols - 1) {
            border = true;
          }
          for(int m = 0; m < 4; ++m) {
            int newRow = row + MOVES[m][0];
            int newCol = col + MOVES[m][1];
            if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
            if(grid[newRow][newCol] || visit[newRow][newCol]) continue;
            visit[newRow][newCol] = true;
            q.push({newRow, newCol});
          }
        }
        if(!border) {
          // cout << r << ' ' << c << endl;
          answer += 1;
        }
      }
    }

    return answer;
  }
};

// Accepted
// 47/47 cases passed (16 ms)
// Your runtime beats 43.87 % of cpp submissions
// Your memory usage beats 23.2 % of cpp submissions (10.3 MB)
// @lc code=end

