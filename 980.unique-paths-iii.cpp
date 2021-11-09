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
  vector<bool> visit;
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
    if(cache.count(path)) return;
    cache.insert(path);
    // cout << ToHex(path) << endl;

    char row = path.back() / cols;
    char col = path.back() % cols;
    if(path.back() == finish) {
      answer += path.length() == target;
      return;
    }

    for(char i = 0; i < 4; ++i) {
      char newRow = row + moves[i][0];
      char newCol = col + moves[i][1];
      if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;
      if(visit[newRow * cols + newCol] || grid[newRow][newCol] == -1) continue;
      visit[newRow * cols + newCol] = true;
      path.push_back(newRow * cols + newCol);
      solve(grid);
      path.pop_back();
      visit[newRow * cols + newCol] = false;
    }
  }
public:
  int uniquePathsIII(vector<vector<int>>& grid) {

    init(grid);
    if(!checkConnection(grid)) {
      return 0;
    }

    unordered_set<string> cache;
    visit.resize(rows * cols);
    path.push_back(start);
    visit[start] = true;
    solve(grid);

    return answer;
  }
};

// Accepted
// 39/39 cases passed (8 ms)
// Your runtime beats 32.66 % of cpp submissions
// Your memory usage beats 22.59 % of cpp submissions (10 MB)
// @lc code=end

