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
    int totalHammingDistance(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> cache;
        int len = nums.size();
        int answer = 0;
        for(int i = 1; i < len; ++i) {
            if(cache.count(nums[i])) {
                answer += cache[nums[i]];
                continue;
            }
            int acc = 0;
            for(int j = 0; j < i; ++j) {
                acc += __builtin_popcount(nums[i]^nums[j]);
            }
            cache[nums[i]] = acc;
            answer += acc;
        }
        return answer;
    }
};

int main() {
  vector<vector<int>> data = {
    {1, 2, 3}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.totalHammingDistance(data);
    cout << ans << endl;
  } 
  return 0;
}