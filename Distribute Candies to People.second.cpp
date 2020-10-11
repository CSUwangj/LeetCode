#include<bits/stdc++.h>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> answer = vector<int>(num_people, 0);
    long long start = 0, end = candies;
    while(start < end) {
      long long mid = (start + end) >> 1;
      if(mid*(1+mid) / 2 >= candies) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    int last_index = end-1;
    int rounds = last_index / num_people;
    int remain = last_index % num_people;
    for(int i = 0; i < num_people; ++i) {
      answer[i] = (i+1) * (last_index/num_people) + num_people*(rounds-1)*rounds/2;
      if(i < remain) {
        answer[i] += i+1 + rounds*num_people;
      }
    }
    answer[remain] += candies - last_index*(last_index+1)/2;
    return answer;
  }
};

int main() {
  vector<pair<int, int>>data = {
    {7, 4}, {10, 3}, {1000000000, 3}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.distributeCandies(data.first, data.second);
    cout << "answer of (" << data.first << ", " << data.second << "): [";
    for(int i = 0; i < ans.size(); ++i) {
      cout << ans[i] << ",]"[i+1==ans.size()];
    }
    cout << endl;
  } 
  return 0;
}