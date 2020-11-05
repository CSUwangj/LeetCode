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
  int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<bitset<300>, int> cnt;
    for(auto &curRow: matrix) {
      bitset<300> row(0);
      bool fliped = curRow.front();
      for(auto cur : curRow) {
        row <<= 1;
        row |= (cur ^ fliped);
      }
      cnt[row] += 1;
    }
    int ans = max_element(
      cnt.begin(),
      cnt.end(),
      [] (const pair<bitset<300>, int> & p1, const pair<bitset<300>, int> & p2) {
        return p1.second < p2.second;
      })->second;
    return ans;
  }
};

int main() {
  vector<vector<vector<int>>> data = {
    {{0,0,0},{0,0,1},{1,1,0}},
    {{0,1},{1,0}}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.maxEqualRowsAfterFlips(data);
    cout << ans << endl;
  } 
  return 0;
}