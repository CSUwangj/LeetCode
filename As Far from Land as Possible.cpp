#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  int bfs(vector<vector<int>>& grid, queue<int>& q) {
    int ans = 0;
    while(q.size()) {
      int i = q.front();
      q.pop();
      int j = q.front();
      q.pop();
      int cnt = q.front();
      q.pop();
      if (cnt > ans) {
        ans = cnt;
      }
      for (int m = 0; m < 4; ++m) {
        if (i+move[m][0] >= 0 && i+move[m][0] < len && j+move[m][1] >= 0 && j+move[m][1] < len &&
            !visited[i+move[m][0]][j+move[m][1]] && !grid[i+move[m][0]][j+move[m][1]]) {
          visited[i+move[m][0]][j+move[m][1]] = true;
          q.push(i+move[m][0]);
          q.push(j+move[m][1]);
          q.push(cnt+1);
        }
      }
    }
    return ans;
  }
  int maxDistance(vector<vector<int>>& grid) {
    queue<int> q;
    len = grid[0].size();
    for(int i = 0; i < grid.size(); ++i) {
      for(int j = 0; j < grid[i].size(); ++j) {
        if(grid[i][j] == 1) {
          q.push(i);
          q.push(j);
          q.push(0);
        }
      }
    }
    if (q.size() == len*len*3 || !q.size()) {
      return -1;
    }
    return bfs(grid, q);
  }
private:
  bool visited[100][100] = {};
  int move[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
  int len;
};


int main() {
  vector<vector<int>> data[] = {
    {{1,0,1},{0,0,0},{1,0,1}},
    {{1,0,0},{0,0,0},{0,0,0}},
    {{0,0,0},{0,0,0},{0,0,0}},
    {{1,1,1},{1,1,1},{1,1,1}},
  };
  for(auto &data: data) {
    auto sol = Solution();
    int ans = sol.maxDistance(data) ;
    cout << ans << endl;
  } 
  return 0;
}