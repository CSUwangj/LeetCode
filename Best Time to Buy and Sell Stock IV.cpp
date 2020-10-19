#include <bits/stdc++.h>
#define LL long long
#define mk(a, b) make_pair(a, b)
#define ULL unsigned long long
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x) & (-x))
using namespace std;

class Solution {
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    for(int i = 1; i < prices.size(); ++i) {
      if(prices[i] > prices[i-1]) ans += prices[i] - prices[i-1];
    }
    return ans;
  }
 public:
  int maxProfit(int k, vector<int>& prices) {
    if(!prices.size()) return 0;
    if(k*2 >= prices.size()) return maxProfit(prices);
    vector<int> dp(prices.size());
    for(int i = 0; i < k; ++i) {
      int previous = dp[0];
      int min_paid = prices[0];
      for(int j = 1; j < prices.size(); ++j) {
        int tmp = dp[j];
        min_paid = min(min_paid, prices[j]-previous);
        dp[j] = max(dp[j-1], prices[j]-min_paid);
        previous = tmp;
      }
    }
    return dp[prices.size()-1];
  }
};

int main() {
  vector<pair<int, vector<int>>> data = {
    {2, {2, 4, 1}},
    {2, {3, 2, 6, 5, 0, 3}},
  };
  for (auto& data : data) {
    auto sol = Solution();
    auto ans = sol.maxProfit(data.first, data.second);
    cout << ans << endl;
  }
  return 0;
}