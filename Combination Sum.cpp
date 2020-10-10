#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  int target;
  int current;
  int index;
public:
  void dfs(vector<vector<int>>& ans, vector<int>& cur, vector<int>& candidates) {
    if(index == candidates.size() || current >= target) {
      if(current == target) {
        ans.push_back(cur);
      }
      return;
    }
    int cnt = 0;
    index += 1;
    dfs(ans, cur, candidates);
    index -= 1;
    while(current < target) {
      current += candidates[index];
      cur.push_back(candidates[index]);
      index += 1;
      cnt += 1;
      dfs(ans, cur, candidates);
      index -= 1;
    }
    while(cnt) {
      cur.pop_back();
      current -= candidates[index];
      cnt -= 1;
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> tmp;
    this->target = target;
    dfs(ans, tmp, candidates);
    return ans;
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