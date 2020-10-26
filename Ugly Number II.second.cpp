#include <bits/stdc++.h>
#define LL long long
#define mk(a, b) make_pair(a, b)
#define ULL unsigned long long
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x) & (-x))
using namespace std;

class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> dp{1};
    int two = 0, three = 0, five = 0;
    while(dp.size() < n) {
      int new_two = dp[two]*2;
      int new_three = dp[three]*3;
      int new_five = dp[five]*5;
      int new_num = min({new_two, new_three, new_five});
      if(new_two == new_num) two += 1;
      if(new_three == new_num) three += 1;
      if(new_five == new_num) five += 1;
      dp.push_back(new_num);
    }
    return dp[n-1];
  }
};

int main() {
  vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1690};
  for (auto &data : data) {
    auto sol = Solution();
    auto ans = sol.nthUglyNumber(data);
    cout << ans << endl;
  }
  return 0;
}