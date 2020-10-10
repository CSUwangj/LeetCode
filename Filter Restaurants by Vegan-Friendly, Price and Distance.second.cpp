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
    vector<int> answer;
    for (int i = 0; i < restaurants.size(); ++i) {
      if (restaurants[i][2] >= veganFriendly && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
        answer.push_back(i);
      }
    }
    sort(answer.begin(), answer.end(), [&restaurants](int a, int b) {
      return restaurants[a][1] > restaurants[b][1] || (restaurants[a][1] == restaurants[b][1] && restaurants[a][0] > restaurants[b][0]);
    });
    for(int i = 0; i < answer.size(); ++i) {
      answer[i] = restaurants[answer[i]][0];
    }
    return answer;
  }
};

int main() {
  vector<vector<int>> data = {{1,4,1,40,10},{2,8,0,50,5},{123,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
  auto sol = Solution();
  auto ans = sol.filterRestaurants(data, 1, 50, 10);
  for(auto& a:ans) {
    cout << a << ' ';
  }
  cout << endl;
  return 0;
}