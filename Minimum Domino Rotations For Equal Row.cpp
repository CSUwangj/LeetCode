#include <bits/stdc++.h>
#define LL long long
#define mk(a, b) make_pair(a, b)
#define ULL unsigned long long
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x) & (-x))
using namespace std;

class Solution {
 public:
  int minDominoRotations(vector<int>& A, vector<int>& B) {
    int ans = -1;
    for (int i = 1; i < 7; ++i) {
      int rowA = 0;
      int rowB = 0;
      int all = 0;
      for (int j = 0; j < A.size(); ++j) {
        rowA += A[j] == i;
        rowB += B[j] == i;
        all += (B[j] == i || A[j] == i);
      }
      if (all == A.size()) {
        ans = max(rowA, rowB);
      }
    }
    return ans == -1 ? -1 : A.size() - ans;
  }
};

int main() {
  vector<tuple<vector<int>, vector<int>>> data = {
      {{2, 1, 2, 4, 2, 2}, {5, 2, 6, 2, 3, 2}},
      {{3, 5, 1, 2, 3}, {3, 6, 3, 3, 4}}};
  for (auto& data : data) {
    auto sol = Solution();
    auto [a, b] = data;
    auto ans = sol.minDominoRotations(a, b);
    cout << ans << endl;
  }
  return 0;
}