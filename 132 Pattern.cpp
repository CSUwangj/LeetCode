// Copyright 2020 <CSUwangj@protonmail.com>
#include <bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x) & (-x))
using namespace std;

class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    if(nums.size() < 3) return false;
    vector<pair<int, int>> s;
    int one = 0, three = -1, i = 1, c = 1, pc = 1;
    while(i < nums.size()) {
      switch (c) {
      case 1:
        if(nums[i] <= nums[i-1]) one = i;
        else pc = 3;
        break;
      case 3:
        if(nums[i] >= nums[i-1]) {
          for(auto &p : s) {
            if(nums[i] > p.first && nums[i] < p.second) {
              return true;
            }
          }
          three = i;
        } else {
          pc = 2;
        }
        break;
      case 2:
        for(int j = s.size()-1; j >=0 && s[j].second <= nums[three]; --j) {
          s.pop_back();
        }
        s.push_back(make_pair(nums[one], nums[three]));
        for(auto &p : s) {
          if(nums[i] > p.first && nums[i] < p.second) return true;
        }
        one = i;
        pc = 1;
      }
      i += pc==c;
      c = pc;
    }
    return false;
  }
};

int main()
{
  vector<vector<int>> data = {
    // {1,2,3,4},
    // {-1,3,4,2,1,5},
    // {3,4,-1,2,3,4},
    // {3,4,-1,2,3,4,2},
    {1,3,-1,8,-7,-3,6},
    // {-1,3,2,0},
    // {3,5,0,3,4}
    // {8,10,4,6,5}
  };
  for (auto &data : data)
  {
    auto sol = Solution();
    auto ans = sol.find132pattern(data);
    cout << (ans ? "yes" : "no") << endl;
  }
  return 0;
}