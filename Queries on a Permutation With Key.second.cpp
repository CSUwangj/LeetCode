#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

s

int main() {
  vector<pair<vector<int>, int>> data = {
    {{3, 1, 2, 1}, 5}, 
    {{4, 1, 2, 2}, 4}, 
    {{7,5,5,8,3}, 8}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.processQueries(data.first, data.second);
    for(int i = 0; i < ans.size(); ++i) {
      cout << ans[i] ;
      if (i == ans.size()-1) cout << endl;
      else cout <<", ";
    }
  } 
  return 0;
}