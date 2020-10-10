#include<bits/stdc++.h>
#include<queue>
#define LL long long
#define mk(a,b) make_pair(a,b)
#define ULL unsigned long long
#define mem(a,n) memset(a,n,sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class RecentCounter {
  queue<int> q;
public:
  int ping(int t) {
    while(q.size() && t - 3000 > q.front()) {
      q.pop();
    }
    q.push(t);
    return q.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
  vector<int> data = {1, 100, 3001, 3002};
  RecentCounter* obj = new RecentCounter();
  for(auto& i : data) {
    cout << obj->ping(i) << endl;
  }
  return 0;
}