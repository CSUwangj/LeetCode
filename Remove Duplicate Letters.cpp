#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  string removeDuplicateLetters(string s) {
    map<char, int> cnt;
    vector<bool> used = vector<bool>(128, false);
    string answer = "";
    for(auto c: s) {
      cnt[c] += 1;
    }
    for(auto c: s) {
      if(used[c]) {
        cnt[c] -= 1;
        continue;
      }
      while(answer.length() && answer.back() > c && cnt[answer.back()]) {
        used[answer.back()] = false;
        answer.pop_back();
      }
      answer.push_back(c);
      cnt[c] -= 1;
      used[c] = true;
    }
    return answer;
  }
};

int main() {
  vector<string> data = {
    "bcabc",
    "cbacdcbc"
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.removeDuplicateLetters(data);
    cout << ans << endl;
  } 
  return 0;
}