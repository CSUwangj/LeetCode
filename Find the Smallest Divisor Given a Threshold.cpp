// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  bool satisfied(vector<int> &nums, int threshold, double divisor) {
    int sum = 0;
    for(auto n : nums) {
      sum += ceil(n/divisor);
    }
    return sum <= threshold;
  }
public:
  int smallestDivisor(vector<int> &nums, int threshold) {
    int start = 1, end = INT_MAX-1;
    while(start < end) {
      int mid = (end + start) / 2;
      if(satisfied(nums, threshold, mid)) end = mid;
      else start = mid + 1; 
    }
    return start;
  }
};

int main() {
  vector<tuple<vector<int>, int>> data = {
    {{2,3,5,7,11}, 11},
    {{1,2,5,9}, 6},
    {{19}, 5}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto [nums, t] = data;
    auto ans = sol.smallestDivisor(nums, t);
    cout << ans << endl;
  } 
  return 0;
}