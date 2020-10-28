// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    if(n < 3) return 0;
    int ans = 0;
    vector<bool> isPrime(n, true);
    for(int i = 2; i*i < n; ++i) {
      if(!isPrime[i]) continue;
      for(int j = i*i; j < n; j += i) {
        isPrime[j] = false;
      }
    }
    for(int i = 2; i < n; ++i) {
      ans += isPrime[i];
    }
    return ans;
  }
};

int main() {
  vector<int> data = {1,2,3,4,5,6,7,8,9,5000000};
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.countPrimes(data);
    cout << ans << endl;
  } 
  return 0;
}