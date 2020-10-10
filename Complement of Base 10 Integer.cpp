#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  int bitwiseComplement(int N) {
    return ~N & ((1 << (32-__builtin_clz(N|1)))-1);
  }
};

int main() {
  auto data = {5, 7, 10, 0};
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.bitwiseComplement(data);
    cout << ans << endl;
  } 
  return 0;
}