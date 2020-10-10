#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  string removeOuterParentheses(string S) {
    stringstream ss;
    int cnt = 0;
    for(int i = 0; i < S.length(); ++i) {
      if(S[i] == '(') {
        if(cnt) ss << S[i];
        cnt += 1;
      } else {
        cnt -= 1;
        if(cnt) ss << S[i];
      }
    }
    return ss.str();
  }
};

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