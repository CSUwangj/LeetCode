#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
    vector<int> id;
    vector<int> ans;
    for(int i = 0; i < restaurants.size(); ++i) {
      id.push_back(i);
    }
    // better than
    // sort(id.begin(), id.end(), [&restaurants](int a, int b){
    //   return restaurants[a][1] > restaurants[b][1] || 
    //     (restaurants[a][1] == restaurants[b][1] && restaurants[a][0] > restaurants[b][0]);
    // });
    // copy_if(id.begin(), id.end(),back_inserter(ans), [&restaurants, veganFriendly, maxDistance, maxPrice](int x){
    //   return restaurants[x][2] >= veganFriendly && restaurants[x][3] <= maxPrice && restaurants[x][4] <= maxDistance;
    // });
    copy_if(id.begin(), id.end(),back_inserter(ans), [&restaurants, veganFriendly, maxDistance, maxPrice](int x){
      return restaurants[x][2] >= veganFriendly && restaurants[x][3] <= maxPrice && restaurants[x][4] <= maxDistance;
    });
    sort(ans.begin(), ans.end(), [&restaurants](int a, int b){
      return restaurants[a][1] > restaurants[b][1] || 
        (restaurants[a][1] == restaurants[b][1] && restaurants[a][0] > restaurants[b][0]);
    });
    transform(ans.begin(), ans.end(), ans.begin(), [&restaurants](int x){ return restaurants[x][0];});
    return ans;
  }
};

int main() {
  vector<vector<int>> data = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
  auto sol = Solution();
  auto ans = sol.filterRestaurants(data, 1, 50, 10);
  for(auto& a:ans) {
    cout << a << ' ';
  }
  cout << endl;
  return 0;
}