#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    int cnt = 0, min_end = -1;
    bool hasBalloon = false;
    for(int i = 0; i < points.size(); ++i) {
      if(!hasBalloon) {
        min_end = points[i][1];
        hasBalloon = true;
      } else {
        if(points[i][0] > min_end) {
          cnt += 1;
          hasBalloon = true;
          min_end = points[i][1];
        } else {
          min_end = min(points[i][1], min_end);
        }
      }
    }
    if(hasBalloon) cnt += 1;
    return cnt;
  }
};

int main() {
  vector<vector<vector<int>>> data = {
    {{10,16},{2,8},{1,6},{7,12}},
    {{1,2},{3,4},{5,6},{7,8}},
    {{2,3},{2,3}}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.findMinArrowShots(data);
    cout << ans << endl;
  } 
  return 0;
}