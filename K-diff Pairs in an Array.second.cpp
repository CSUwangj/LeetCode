#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    map<int, int> m;
    for(int i = 0; i < nums.size(); ++i) {
      m[nums[i]] += 1;
    }
    int ans = 0;
    if(k == 0) {
      for(auto const& [key, value] : m) {
        if(value > 1) ans += 1;
      }
    } else {
      for(auto const& [key, value] : m) {
        if(m[value-k]) ans += 1;
        if(m[value+k]) ans += 1;
      }
      ans /= 2;
    }
    return ans;
  }
};

int main() {
  vector<pair<vector<int>, int>> data = {
    {{1,2,4,4,3,3,0,9,2,3}, 3},
    {{1,3,1,5,4}, 0},
    {{1,2,3,4,5}, 1},
    {{3,1,4,1,5}, 2}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.findPairs(data.first, data.second);
    cout << ans << endl;
  } 
  return 0;
}