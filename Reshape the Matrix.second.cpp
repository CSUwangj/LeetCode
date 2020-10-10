#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if(nums.size() * nums[0].size() != r * c) return nums;
    vector<vector<int>> ans;
    vector<int> tmp;
    for(int i = 0; i < r*c; ++i) {
      tmp.push_back(nums[i/nums[0].size()][i%nums[0].size()]);
      if(tmp.size() == c) {
        ans.push_back(tmp);
        tmp.clear();
      }
    }
    return ans;
  }
};

int main() {
  vector<pair<pair<vector<vector<int>>, int>, int>> data = {
    {{{{1, 2}, {3, 4}}, 1}, 4},
    {{{{1, 2}, {3, 4}}, 2}, 4},
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto tmp = data.first;
    auto ans = sol.matrixReshape(tmp.first, tmp.second, data.second);
    cout << '[';
    for(int i = 0; i < ans.size(); ++i){
      cout << '[';
      for(int j = 0; j < ans[i].size(); ++j){
        cout << ans[i][j] << ',';
      }
      cout << ']' << ',';
    }
    cout << ']' << endl;
  } 
  return 0;
}