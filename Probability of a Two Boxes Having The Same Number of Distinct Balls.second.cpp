#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  long long c[50][50];
  long long perms;
  int total = 0;
  void init() {
    for (int i = 1; i < 50; i++) {
      c[i][i] = 1;
      c[i][0] = 1;
      for (int j = 1; j < i; ++j) {
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
      }
    }
  }
public:
  void dfs(int color1, int color2, int balls1, int balls2, int index, long long ways, vector<int>& balls) {
    // cout << color1 << ' ' << color2 << ' ' << balls1 << ' ' << balls2 << ' ' << index << ' ' << ways << endl;
    if(index == balls.size()) {
      if (color1 == color2 && balls1 == balls2) {
        perms += ways;
      }
      return;
    }
    for(int i = 0; i <= balls[index]; i++) {
      if(balls1 <= total/2 && balls2 <= total/2){
        dfs(color1+(i==0), color2+(i==balls[index]), balls1+i, balls2+balls[index]-i, index+1, ways*c[balls[index]][i], balls);
      }
    }
  }
  double getProbability(vector<int>& balls) {
    for(int i = 0; i < balls.size(); ++i) {
      total += balls[i];
    }
    init();
    dfs(0, 0, 0, 0, 0, 1, balls);
    return 1.0*perms/c[total][total/2];
  }
};

int main() {
  vector<vector<int>> data = {
    {6,6,6,6,6,6},
    {3,2,1},
    {1,2,1,2}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.getProbability(data);
    cout << ans << endl;
  } 
  return 0;
}