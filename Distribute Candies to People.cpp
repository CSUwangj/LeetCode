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
    vector<int> answer(num_people);
    long long begin = 0, end=sqrt(candies)*1.6;
    while (begin < end) {
      long long mid = (begin + end)/2;
      if(mid*(mid+1)/2 > candies) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    long long turns = end - 1;
    long long rounds = turns / num_people, remainder = turns % num_people, last = candies - turns*(turns+1)/2;
    for(int i = 0; i < num_people; ++i) {
      answer[i] = (i+1) * rounds + (rounds-1)*rounds*num_people/2;
      if(i < remainder) {
        answer[i] += rounds*num_people + i+1;
      }
    }
    answer[remainder] += last;
    return answer;
  }
};

int main() {
  vector<pair<int, int>>data = {
    {7, 4}, {10, 3}, {1000000000, 1}
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