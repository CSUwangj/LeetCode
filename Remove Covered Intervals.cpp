#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    int removeCount = 0;
    for(int i = 0; i < intervals.size(); ++i) {
      for(int j = 0; j < intervals.size(); ++j) {
        if(i != j && intervals[j][0] <= intervals[i][0] && intervals[j][1] >= intervals[i][1]) {
          removeCount += 1;
          break;
        }
      }
    }
    return intervals.size() - removeCount;
  }
};

int main() {
  vector<vector<vector<int>>> data = {
    {{1,4}, {3,6}, {2,8}},
    {{1,4}, {2,3}},
    {{0, 10}, {5, 12}},
    {{34335,39239},{15875,91969},{29673,66453},{53548,69161},{40618,93111}}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.removeCoveredIntervals(data);
    cout << ans << endl;
  } 
  return 0;
}