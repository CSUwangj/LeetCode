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
  int mirrorReflection(int p, int q) {
    if(q == 0) return 0;
    int answer = -1;
    int minRound = INT_MAX;
    for(int i = 0; i < q; ++i) {
      if((i*2+1)*p % q == 0) {
        minRound = i*2 + 1;
        answer = 2 - (((i*2+1)*p/q) & 1);
        break;
      }
    }
    int end = q / gcd(p, q);
    for(int i = 0; i < end; ++i) {
      if((2*i+2)*p % q == 0) {
        if((i*2+2) < minRound) {
          answer = 0;
        }
        break;
      }
    }
    return answer;
  }
};

int main() {
  vector<tuple<int, int>> data = {
    {2, 1},
    {3, 1},
    {3, 2}
  };
  for(auto &[p, q]: data) {
    auto sol = Solution();
    auto ans = sol.mirrorReflection(p, q);
    cout << ans << endl;
  } 
  return 0;
}