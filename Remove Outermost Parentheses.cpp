#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

WWW

int main() {
  vector<string> data = {
    "(()())(())",
    "(()())(())(()(()))",
    "()()",
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.removeOuterParentheses(data) ;
    cout << ans << endl;
  } 
  return 0;
}