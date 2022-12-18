/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
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
public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int rows = maze.size();
    int cols = maze.front().size();
    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});
    maze[entrance[0]][entrance[1]] = '+';
    int step = 0;
    while(q.size()) {
      int sz = q.size();
      while(sz--) {
        auto [row, col] = q.front();
        q.pop();
        if(step && (!row || !col || row == rows - 1 || col == cols - 1)) {
          return step;
        }
        for(int i = 0; i < 4; ++i) {
          int newRow = row + moves[i][0];
          int newCol = col + moves[i][1];
          if(newRow < 0 || newCol < 0 || newRow == rows || newCol == cols) {
            continue;
          }
          if(maze[newRow][newCol] == '.') {
            q.push({newRow, newCol});
            maze[newRow][newCol] = '+';
          }
        }
      } 
      step += 1;
    }
    return -1;
  }
};

// Accepted
// 194/194 cases passed (107 ms)
// Your runtime beats 99.9 % of cpp submissions
// Your memory usage beats 98.88 % of cpp submissions (29.7 MB)
// @lc code=end

