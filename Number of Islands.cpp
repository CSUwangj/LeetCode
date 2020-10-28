// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  vector<vector<int>> move{{1,0},{0,1},{-1,0},{0,-1}};
public:
  int numIslands(vector<vector<char>>& grid) {
    int sz = grid.size() * grid[0].size(), width = grid[0].size(), height = grid.size(), ans = 0;
    vector<vector<bool>> visited(height, vector<bool>(width));
    queue<pair<int, int>> start_points, q;
    for(int i = 0; i < height; ++i) {
      for(int j = 0; j < width; ++j) {
        if(grid[i][j] == '1') {
          start_points.push(make_pair(i, j));
        }
      }
    }
    while(start_points.size()) {
      auto start_point = start_points.front();
      start_points.pop();
      if(visited[start_point.first][start_point.second]) {
        continue;
      }
      ans += 1;
      visited[start_point.first][start_point.second] = true;
      q.push(start_point);
      while(q.size()) {
        auto tmp = q.front();
        int row = tmp.first, col = tmp.second;
        q.pop();
        for(int i = 0; i < 4; ++i) {
          int nrow = row+move[i][0], ncol = col+move[i][1];
          if(nrow < height && nrow >=0 && ncol < width && ncol >=0 &&
            grid[nrow][ncol] == '1' && !visited[nrow][ncol]) {
            q.push(make_pair(nrow, ncol));
            visited[nrow][ncol] = true;
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  vector<vector<vector<char>>> data = {
    {{'1', '1', '1', '1', '0'},
      {'1', '1', '0', '1', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '0', '0', '0'}},
    {{'1', '1', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '1', '1'}}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.numIslands(data);
    cout << ans << endl;
  } 
  return 0;
}