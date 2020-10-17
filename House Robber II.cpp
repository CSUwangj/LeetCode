#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);
    vector<int> dp(nums.size()-1);
    dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < nums.size()-1; ++i) {
      dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }
    int ans = dp[dp.size()-1];
    dp[0] = nums[1], dp[1] = max(nums[1], nums[2]);
    for(int i = 3; i < nums.size(); ++i) {
      dp[i-1] = max(dp[i-2], dp[i-3]+nums[i]);
    }
    ans = max(ans, dp[dp.size()-1]);
    return ans;
  }
};

int main() {
  vector<vector<int>> data = {
    {1,3,1,3,100}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.rob(data);
    cout << ans << endl;
  } 
  return 0;
}