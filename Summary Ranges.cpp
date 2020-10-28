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
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    if(nums.empty()) return ans;
    int begin = nums[0], end = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
      if(nums[i]-1 != end) {
        string tmp = to_string(begin);
        if(end != begin) tmp += "->"+to_string(end);
        ans.push_back(tmp);
        begin = nums[i];
        end = nums[i];
      } else {
        end = nums[i];
      }
    }
    string tmp = to_string(begin);
    if(end != begin) tmp += "->"+to_string(end);
    ans.push_back(tmp);
    return ans;
  }
};

int main() {
  vector<vector<int>> data = {
    {0,1,2,4,5,7},
    {0,2,3,4,6,8,9},
    {},
    {-1}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.summaryRanges(data);
    cout << "<<<<<<<<<<<<<<<<" << endl;
    for(auto &s : ans) {
      cout << '"' << s << '"' << endl;
    }
    cout << "<<<<<<<<<<<<<<<<" << endl;
  } 
  return 0;
}