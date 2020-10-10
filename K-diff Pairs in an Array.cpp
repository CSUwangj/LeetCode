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
    sort(nums.begin(), nums.end());
    int ans = 0;
    if(k == 0) {
      int last_pair = -10000001;
      for (int i = 1; i < nums.size(); ++i) {
        if(nums[i] == nums[i-1] && nums[i] != last_pair) {
          ans += 1;
          last_pair = nums[i];
        }
      }
      return ans;
    }
    auto end = unique(nums.begin(), nums.end());
    auto front = nums.begin();
    for(auto back = nums.begin()+1; back != end; ++back) {
      while(front+1 != back && *back - *front > k) ++front;
      if(*back - *front == k) ++ans;
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