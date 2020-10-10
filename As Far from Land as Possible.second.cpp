#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  int length;
  int move[4][2] = {
    {-1,0}, 
    {0, 1},
    {1, 0},
    {0,-1}
  };
  bool isValid(int first, int second) {
    return first >= 0 && second >= 0 && first < length && second < length;
  }
  int bfs(vector<vector<int>>& grid, queue<tuple<int, int, int>>& q) {
    int ans = 0;
    while(q.size()) {
      // auto [ x, y, cnt ] = q.front();
      int x = get<0>(q.front());
      int y = get<1>(q.front());
      int cnt = get<2>(q.front());
      q.pop();
      if(cnt > ans) ans = cnt;
      for(int i = 0; i < 4; ++i) {
        if(isValid(x+move[i][0], y+move[i][1]) && !grid[x+move[i][0]][y+move[i][1]]) {
          q.push(make_tuple(x+move[i][0], y+move[i][1], cnt+1));
          grid[x+move[i][0]][y+move[i][1]] = 1;
        }
      }
    }
    return ans;
  }
public:
  int maxDistance(vector<vector<int>>& grid) {
    queue<tuple<int, int, int>> q;
    length = grid.size();
    for(int i = 0; i < length; i++) {
      for(int j = 0; j < length; j++) {
        if(grid[i][j] == 1) {
          q.push(make_tuple(i, j, 0));
        }
      }
    }
    if (q.size() == length * length || q.empty()) {
      return -1;
    }
    return bfs(grid, q);
  }
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