/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
const char moves[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
  char rows;
  char cols;
  char start;
  char finish;
  char obstacles;
  char target;
  char answer;
  char count = 1;
  void init(vector<vector<int>> &grid) {
    rows = grid.size();
    cols = grid.front().size();
    for(int i = 0; i < rows; ++i) {
      for(char j = 0; j < cols; ++j) {
        switch(grid[i][j]) {
          case 1:
            start = i * cols + j;
            break;
          case 2:
            finish = i * cols + j;
            break;
          case -1:
            obstacles += 1;
          default:
            ;
        }
      }
    }
    target = rows * cols - obstacles;
  }
  void solve(vector<vector<int>>& grid, char pos) {
    // cout << ToHex(path) << endl;

    char row = pos / cols;
    char col = pos % cols;
    if(pos == finish) {
      answer += count == target;
      return;
    }
    grid[row][col] = -1;

    for(char i = 0; i < 4; ++i) {
      char newRow = row + moves[i][0];
      char newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
      if(grid[newRow][newCol] == -1) continue;
      count += 1;
      solve(grid, newRow * cols + newCol);
      count -= 1;
    }
    grid[row][col] = 0;
  }
public:
  int uniquePathsIII(vector<vector<int>>& grid) {

    init(grid);

    solve(grid, start);

    return answer;
  }
};

// Accepted
// 39/39 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 67.27 % of cpp submissions (7.1 MB)
// @lc code=end

