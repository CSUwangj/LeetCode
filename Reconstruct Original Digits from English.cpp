#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  int cnt[256];
public:
  string originalDigits(string s) {
    for(auto &a: s) {
      cnt[a] += 1;
    }
    while(cnt['z']) {
      cnt['z'] -= 1;
      cnt['e'] -= 1;
      cnt['r'] -= 1;
      cnt['o'] -= 1;
      cnt[0] += 1;
    }
    while(cnt['x']) {
      cnt['s'] -= 1;
      cnt['i'] -= 1;
      cnt['x'] -= 1;
      cnt[6] += 1;
    }
    while(cnt['w']) {
      cnt['t'] -= 1;
      cnt['w'] -= 1;
      cnt['o'] -= 1;
      cnt[2] += 1;
    }
    while(cnt['g']) {
      cnt['e'] -= 1;
      cnt['i'] -= 1;
      cnt['g'] -= 1;
      cnt['h'] -= 1;
      cnt['t'] -= 1;
      cnt[8] += 1;
    }
    while(cnt['s']) {
      cnt['s'] -= 1;
      cnt['e'] -= 1;
      cnt['v'] -= 1;
      cnt['e'] -= 1;
      cnt['n'] -= 1;
      cnt[7] += 1;
    }
    while(cnt['v']) {
      cnt['f'] -= 1;
      cnt['i'] -= 1;
      cnt['v'] -= 1;
      cnt['e'] -= 1;
      cnt[5] += 1;
    }
    while(cnt['f']) {
      cnt['f'] -= 1;
      cnt['o'] -= 1;
      cnt['u'] -= 1;
      cnt['r'] -= 1;
      cnt[4] += 1;
    }
    while(cnt['t']) {
      cnt['t'] -= 1;
      cnt['h'] -= 1;
      cnt['r'] -= 1;
      cnt['e'] -= 1;
      cnt['e'] -= 1;
      cnt[3] += 1;
    }
    while(cnt['i']) {
      cnt['n'] -= 1;
      cnt['i'] -= 1;
      cnt['n'] -= 1;
      cnt['e'] -= 1;
      cnt[9] += 1;
    }
    while(cnt['o']) {
      cnt['o'] -= 1;
      cnt['n'] -= 1;
      cnt['e'] -= 1;
      cnt[1] += 1;
    }
    stringstream ss;
    for(int i = 0; i < 10; ++i) {
      while(cnt[i]) {
        ss << i;
        cnt[i] -= 1;
      }
    }
    return ss.str();
  }
};

int main() {
  string data[] = {
    "owoztneoer",
    "fviefuro"
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.originalDigits(data);
    cout << ans << endl;
  } 
  return 0;
}