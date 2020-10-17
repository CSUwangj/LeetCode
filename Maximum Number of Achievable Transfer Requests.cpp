#include <bits/stdc++.h>
#define LL long long
#define mk(a, b) make_pair(a, b)
#define ULL unsigned long long
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x) & (-x))
using namespace std;

class Solution {
    bool isOk(vector<vector<int>>& requests, vector<int>& trans, int bitmask) {
      for(int i = 0; i < requests.size(); ++i) {
        if(bitmask & (1 << i)) {
          trans[requests[i][0]] += 1;
          trans[requests[i][1]] -= 1;
        }
      }
      for(int i = 0; i < trans.size(); ++i) {
        if(trans[i] != 0) return false;
      }
      return true;
    }
 public:
  int maximumRequests(int n, vector<vector<int>>& requests) {
    int cur = requests.size();
    vector<int> trans(n+1);
    while(cur) {
      for (int mask = (1<<cur) - 1, t; mask < 1 << requests.size(); mask = (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(mask) + 1)) ) {
        // cout << mask << ' ' << bitset<20>(mask) << endl;
        if(isOk(requests, trans, mask)) return cur;
        fill(trans.begin(), trans.end(), 0);
        t = mask | (mask - 1);
      }
      cur -= 1;
    }
    return 0;
  }
};

int main() {
  vector<pair<int, vector<vector<int>>>> data = {
    {5, {{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}}},
    {3, {{0,0},{1,2},{2,1}}},
    {4, {{0,3},{3,1},{2,0}}}
  };
  for (auto& data : data) {
    auto sol = Solution();
    auto ans = sol.maximumRequests(data.first, data.second);
    cout << ans << endl;
  }
  return 0;
}