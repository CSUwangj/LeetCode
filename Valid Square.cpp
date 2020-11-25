// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    vector<vector<int>> points{p1, p2, p3, p4};
    sort(points.begin(), points.end(), [](vector<int> &p1, vector<int> &p2) {
      return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
    });
    int diffX1 = points[0][0] - points[3][0], diffX2 = points[1][0] - points[2][0];
    int diffY1 = points[0][1] - points[3][1], diffY2 = points[1][1] - points[2][1];
    int len1 = (diffX1*diffX1 + diffY1*diffY1), len2 = (diffX2*diffX2 + diffY2*diffY2);
    int len3 = (points[0][0] - points[1][0])*(points[0][0] - points[1][0]) + (points[0][1] - points[1][1])*(points[0][1] - points[1][1]);
    int len4 = (points[2][0] - points[3][0])*(points[2][0] - points[3][0]) + (points[2][1] - points[3][1])*(points[2][1] - points[3][1]);
    if(len1 == len2 && len3 == len4 && len3 != 0 && len1 != 0 && diffX2*diffX1 + diffY1*diffY2 == 0) return true;
    return false;
  }
};

int main() {
  vector<tuple<vector<int>, vector<int>, vector<int>, vector<int>>> data = {
    {{0,0}, {1,1}, {1,0}, {0,1}},
    {{1,0}, {-1,0}, {0,1},{0,-1}},
    {{0,0}, {-1,0}, {1,0}, {0,1}},
    {{2,1}, {1,2}, {0,0}, {2,0}}
  };
  for(auto &[p1, p2, p3, p4]: data) {
    auto sol = Solution();
    auto ans = sol.validSquare(p1, p2, p3, p4);
    cout << ans << endl;
  } 
  return 0;
}