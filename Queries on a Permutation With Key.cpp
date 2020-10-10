#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  vector<int> processQueries(vector<int>& queries, int m) {
    list<int> permutation;
    vector<int> ans;
    for(int i = 0; i < m; ++i) {
      permutation.push_back(i+1);
    }
    for(int i = 0; i < queries.size(); ++i) {
      auto it = find(permutation.begin(), permutation.end(), queries[i]);
      ans.push_back(distance(permutation.begin(), it));
      permutation.erase(it);
      permutation.push_front(queries[i]);
    }
    return ans;
  }
};

int main() {
  vector<pair<vector<int>, int>> data = {
    {{3, 1, 2, 1}, 5}, 
    {{4, 1, 2, 2}, 4}, 
    {{7,5,5,8,3}, 8}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.processQueries(data.first, data.second);
    for(int i = 0; i < ans.size(); ++i) {
      cout << ans[i] ;
      if (i == ans.size()-1) cout << endl;
      else cout <<", ";
    }
  } 
  return 0;
}