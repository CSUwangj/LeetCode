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
  int maxDistToClosest(vector<int>& seats) {
    vector<int> left(seats.size());
    vector<int> right(seats.size());
    int left_most = -20000;
    int right_most = 40000;
    for(int i = 0; i < seats.size(); ++i) {
      if(seats[i] == 1) left_most = i;
      else left[i] = left_most;
    }
    for(int i = seats.size()-1; i >= 0; --i) {
      if(seats[i] == 1) right_most = i;
      else right[i] = right_most;
    }
    int ans = -1;
    for(int i = 0; i < seats.size(); ++i) {
      if(!seats[i]) ans = max(ans, min(i-left[i], right[i]-i));
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> data = {
    {1,0,0,0,1,0,1},
    {1,0,0,0},
    {0,1}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.maxDistToClosest(data);
    cout << ans << endl;
  } 
  return 0;
}