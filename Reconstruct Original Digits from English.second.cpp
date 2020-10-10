#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  int cnt[10];
public:
  string originalDigits(string s) {
    for(int i = 0; i < s.length(); ++i) {
      switch(s[i]){
        case 'z':
          cnt[0] += 1;
          break;
        case 'w':
          cnt[2] += 1;
          break;
        case 'x':
          cnt[6] += 1;
          break;
        case 'g':
          cnt[8] += 1;
          break;
        case 's':
          cnt[7] += 1;
          break;
        case 'v':
          cnt[5] += 1;
          break;
        case 'f':
          cnt[4] += 1;
          break;
        case 't':
          cnt[3] += 1;
          break;
        case 'o':
          cnt[1] += 1;
          break;
        case 'i':
          cnt[9] += 1;
          break;
      }
    }
    cnt[7] -= cnt[6];
    cnt[5] -= cnt[7];
    cnt[4] -= cnt[5];
    cnt[3] -= cnt[2] + cnt[8];
    cnt[1] -= cnt[0] + cnt[2] + cnt[4];
    cnt[9] -= cnt[6] + cnt[8] + cnt[5];
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
    "fviefuro",
    "xsi"
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.originalDigits(data);
    cout << ans << endl;
  } 
  return 0;
}