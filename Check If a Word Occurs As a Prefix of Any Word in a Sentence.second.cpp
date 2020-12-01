#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  vector<int> next;
  void build_next(string& s) {
    next.push_back(-1);
    int cur = 0;
    for(int i = 1; i < s.length(); ++i) {
      while(cur && s[i] != s[cur]) {
        cur = next[cur];
      }
      if(s[i] == s[cur]) {
        cur += 1;
      }
      next.push_back(cur);
    }
  }
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    build_next(searchWord);
    int cnt = 0, cur = 0;
    for(int i = 0; i < sentence.length(); ++i) {
      if(sentence[i] == ' ') {
        cur = 0;
        cnt += 1;
        continue;
      }
      while(cur && sentence[i] != searchWord[cur]) {
        cur = next[cur];
      }
      if(sentence[i] == searchWord[cur]) {
        cur += 1;
      }
      if(cur == searchWord.length()) {
        if(i-cur < 0 || sentence[i-cur] == ' ') return cnt+1;
        else cur = 0;
      }
    }
    return -1;
  }
};

int main() {
  vector<pair<string,string>> data = {
    // {"i love eating burger", "burg"},
    // {"this problem is an easy problem", "pro"},
    // {"i am tired",  "you"},
    {"", "aaaaa"}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.isPrefixOfWord(data.first, data.second);
    cout << ans << endl;
  } 
  return 0;
}