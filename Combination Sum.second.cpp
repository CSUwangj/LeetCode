#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  vector<vector<vector<int>>> ans;
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> ttmp;
    for(int i = 0; i <= target; ++i) {
      vector<vector<int>> tmp;
      ans.push_back(tmp);
    }
    ans[0].push_back(ttmp);
    for(int i = 0; i < candidates.size(); ++i) {
      for(int j = candidates[i]; j <= target; ++j) {
        if(ans[j-candidates[i]].size()) for(int k = 0; k < ans[j-candidates[i]].size(); ++k) {
          ttmp = ans[j-candidates[i]][k];
          ttmp.push_back(candidates[i]);
          cout << j << ' ' << ans[j].size() << endl;
          ans[j].push_back(ttmp);
        }
      }
    }
    return ans[target];
  }
};

int main() {
  vector<pair<vector<int>, int>> data = {
    {{2,3,5}, 8},
    {{2,3,6,7}, 7}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.combinationSum(data.first, data.second);
    for(int i = 0; i < ans.size(); ++i) {
      for(int j = 0; j < ans[i].size(); ++j) {
        cout << ans[i][j] << " ";
      }
      cout << endl;
    }
  } 
  return 0;
}