#include<bits/stdc++.h>
#include<queue>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class RecentCounter {
  vector<int> calls;
  int begin;
public:
  int ping(int t) {
    calls.push_back(t);
    if(calls.size() == 1 || t-3000 <= calls[begin]) {
      return calls.size()-begin;
    }
    int end = calls.size();
    while(begin < end) {
      int mid = (begin + end) / 2;
      if(calls[mid] < t-3000) {
        begin = mid+1;
      } else {
        end = mid;
      }
    }
    begin = end;
    return calls.size()-begin;
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
  vector<int> data = {642, 1849, 4921, 5936, 5957};
  RecentCounter* obj = new RecentCounter();
  for(auto& i : data) {
    cout << obj->ping(i) << endl;
  }
  return 0;
}