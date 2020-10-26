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
  bool winnerSquareGame(int n) {
    vector<bool> state{false};
    int cur = 1;
    while(state.size() <= n) {
      bool win = false;
      for(int i = 1; i <= cur; ++i) {
        if(!state[state.size()-i*i]) {
          win = true;
          break;
        }
      }
      state.push_back(win);
      if(state.size() == (cur+1)*(cur+1)) cur += 1;
    }
    return state[n];
  }
};

int main() {
  vector<int> data = {
    1,2,3,4,5,6,7,8,9,10,11,12,13,14
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.winnerSquareGame(data);
    cout << data << ' ' << ans << endl;
  } 
  return 0;
}