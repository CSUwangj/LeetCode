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
  int bagOfTokensScore(vector<int>& tokens, int P) {
    sort(tokens.begin(), tokens.end());
    int head = 0, tail = tokens.size();
    int ans = 0, cur = 0;
    while(head != tail) {
      while(head != tail && P >= tokens[head]) {
        P -= tokens[head];
        cur += 1;
        head += 1;
      }
      ans = max(ans, cur);
      if(!cur || head == tail) break;
      tail -= 1;
      cur -= 1;
      P += tokens[tail];
    }
    return ans;
  }
};

int main() {
  vector<tuple<vector<int>, int>> data = {
    {{100,200,300,400}, 200},
    {{100,200,300,400}, 1000},
    {{100,200}, 150}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto [token, P] = data;
    auto ans = sol.bagOfTokensScore(token, P);
    cout << ans << endl;
  } 
  return 0;
}