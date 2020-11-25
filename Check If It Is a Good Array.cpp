// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  vector<int> primes;
  vector<bool> isPrime;
  void init(int maxNum) {
    maxNum = ceil(sqrt(maxNum));
    isPrime.resize(maxNum+1);
    for(int i = 2; i <= maxNum; ++i) {
      if(isPrime[i]) {
        primes.push_back(i);
      }
      for(int j = i*i; j <= maxNum; j += i) {
        isPrime[j] = false;
      }
    }
  }
public:
  bool isGoodArray(vector<int>& nums) {
    int minNum = *min_element(nums.begin(), nums.end());
    if(minNum == 1) return true;
    int maxNum = *max_element(nums.begin(), nums.end());
    init(maxNum);
    unordered_map<int, bool> visited;
    for(auto num : nums) {
      
      for(auto prime : primes) {
        if(num % prime == 0) {
          if(visited[num]) return
        }
      }
    }
  }
};

int main() {
  vector<vector<int>> data = {};
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol. ;
    cout << ans << endl;
  } 
  return 0;
}