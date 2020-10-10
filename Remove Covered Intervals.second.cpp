#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
using namespace std;

class Solution {
  vector<int> bit;
  int lowbit(int x) {
    return x&(-x);
  }
  int sum(int x) {
    int ans = bit[0];
    while(x) {
      ans += bit[x];
      x -= lowbit(x);
    }
    return ans;
  }
  void add(int pos, int val) {
    if (pos == 0) {
      bit[0] = val;
      pos = 1;
    }
    while(pos < bit.size()) {
      bit[pos] += val;
      pos += lowbit(pos);
    }
  }
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] > b[1] || (a[1] == b[1] && a[0] < b[0]);
    });
    int removeCount = 0;
    bit = vector<int>(intervals[0][1]+1, 0);
    for(int i = 0; i < intervals.size(); ++i) {
      removeCount += !!sum(intervals[i][0]);
      // cout << intervals[i][0] << endl;
      add(intervals[i][0], 1);
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