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
  unordered_set<string> cache;
  string path;
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
  bool checkConnection(vector<vector<int>>& grid) {
    queue<pair<char, char>> q;
    bool vis[rows][cols];
    memset(vis, 0, sizeof(vis));
    vis[start / cols][start % cols] = true;
    q.push({start / cols, start % cols});

    while(q.size()) {
      auto [row, col] = q.front();
      if(row * cols + col == finish) return true;
      q.pop();
      for(char i = 0 ; i < 4; ++i) {
        char newRow = row + moves[i][0];
        char newCol = col + moves[i][1];
        if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
        if(vis[newRow][newCol] || grid[newRow][newCol] == -1) continue;
        vis[newRow][newCol] = true;
        q.push({newRow, newCol});
      }
    }
    return false;
  }
  void solve(vector<vector<int>>& grid) {
    // cout << ToHex(path) << endl;

    char row = path.back() / cols;
    char col = path.back() % cols;
    if(path.back() == finish) {
      answer += path.length() == target;
      return;
    }
    grid[row][col] = -1;

    for(char i = 0; i < 4; ++i) {
      char newRow = row + moves[i][0];
      char newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
      if(grid[newRow][newCol] == -1) continue;
      path.push_back(newRow * cols + newCol);
      solve(grid);
      path.pop_back();
    }
    grid[row][col] = 0;
  }
public:
  int uniquePathsIII(vector<vector<int>>& grid) {

    init(grid);
    if(!checkConnection(grid)) {
      return 0;
    }

    path.push_back(start);
    solve(grid);

    return answer;
  }
};

// Accepted
// 39/39 cases passed (4 ms)
// Your runtime beats 74.46 % of cpp submissions
// Your memory usage beats 36.83 % of cpp submissions (7.2 MB)
// @lc code=end

