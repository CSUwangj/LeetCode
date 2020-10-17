#include <bits/stdc++.h>
#define LL long long
#define mk(a, b) make_pair(a, b)
#define ULL unsigned long long
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x) & (-x))
using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    if(s.size() <= 10) return ans;
    map<string, int> mp;
    for(auto it = s.begin(), ite = it+10; ite != s.end(); ++it, ++ite) {
      string news(it,ite);
      mp[news] += 1;
    }
    string new(s.end()-10, s.end());
    mp[new] += 1;
    for(auto it : mp) {
      if(it.second > 1) {
        ans.push_back(it.first);
      }
    }
    return ans;
  }
};

int main() {
  vector<string> data = {
    "AAAAACCCCCAAAAACCCCCAAAAAGGGTTT",
    "AAAAAAAAAAA"
  };
  for (auto &data : data) {
    auto sol = Solution();
    auto ans = sol.findRepeatedDnaSequences(data);
  }
  return 0;
}