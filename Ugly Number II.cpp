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
    set<long long> s;
    s.insert(1);
    auto it = s.begin();
    while(--n) {
      s.insert(it, *it*2);
      s.insert(it, *it*3);
      s.insert(it, *it*5);
      ++it;
    }
    return *it;
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