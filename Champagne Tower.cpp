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
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<double> rows(query_row+1);
    rows[0] = poured;
    for(int i = 0; i < query_row; ++i) {
      for(int j = i; j >= 0; --j) {
        rows[j] = rows[j] > 1.0 ? rows[j]-1.0 : 0;
        rows[j+1] += rows[j] / 2;
        rows[j] /= 2;
      }
    }
    return min(1.0, rows[query_glass]);
  }
};

int main() {
  vector<tuple<int, int, int>> data = {
    {1,1,1},
    {2,1,1},
    {100000009,33,17}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto [para0, para1, para2] = data;
    auto ans = sol.champagneTower(para0, para1, para2);
    cout << ans << endl;
  } 
  return 0;
}