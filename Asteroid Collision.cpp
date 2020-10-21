#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    for(int i = 0; i < asteroids.size(); ++i){
      if(asteroids[i] > 0){
        ans.push_back(asteroids[i]);
        continue;
      }
      bool have = true;
      for(int j = ans.size()-1; j >= 0 && have; --j) {
        if(ans[j] < 0) break;
        if(-asteroids[i] > ans[j]) {
          ans.pop_back();
        } else if(-asteroids[i] < ans[j]) {
          have = false;
        } else {
          ans.pop_back();
          have = false;
        }
      }
      if(have) ans.push_back(asteroids[i]);
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> data = {
    {5,10,-5},
    {8,-8},
    {10,2,-5},
    {-2,-1,1,2}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.asteroidCollision(data);
    cout << '[';
    for(auto i : ans) {
      cout << i << ',';
    }
    cout << ']' << endl;
  } 
  return 0;
}