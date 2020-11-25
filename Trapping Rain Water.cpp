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
  int trap(vector<int>& height) {
    int len = height.size();
    vector<int> nextEqualGreater(len);
    vector<int> lastEqualGreater(len);
    vector<int> monoStack;
    for(int i = len-1; i >= 0; --i) {
      while(monoStack.size() && height[monoStack.back()] < height[i]) monoStack.pop_back();
      nextEqualGreater[i] = monoStack.empty() ? -1 : monoStack.back();
      monoStack.push_back(i);
    }
    while(monoStack.size()) monoStack.pop_back();
    for(int i = 0; i < len; ++i) {
      while(monoStack.size() && height[monoStack.back()] < height[i]) monoStack.pop_back();
      lastEqualGreater[i] = monoStack.empty() ? -1 : monoStack.back();
      monoStack.push_back(i);
    }
    int leftPos = 1;
    while(leftPos < len && height[leftPos] >= height[leftPos-1]) leftPos += 1;
    if(leftPos == len) return 0;
    int rightPos = len - 2;
    while(rightPos >= 0 && height[rightPos] >= height[rightPos+1]) rightPos -= 1;
    if(rightPos == -1) return 0;

    leftPos -= 1;
    rightPos += 1;
    int answer = 0;
    while(leftPos < rightPos) {
      if(nextEqualGreater[leftPos] != -1) {
        int waterHeight = min(height[leftPos], height[nextEqualGreater[leftPos]]);
        for(int current = leftPos + 1, end = nextEqualGreater[leftPos] -1; current <= end; ++current) {
          answer += waterHeight - height[current];
        }
        leftPos = nextEqualGreater[leftPos];
      } else if (lastEqualGreater[rightPos] != -1) {
        int waterHeight = min(height[rightPos], height[lastEqualGreater[rightPos]]);
        for(int current = lastEqualGreater[rightPos] + 1, end = rightPos -1; current <= end; ++current) {
          answer += waterHeight - height[current];
        }
        rightPos = lastEqualGreater[rightPos];
      }
    }
    return answer;
  }
};

int main() {
  vector<vector<int>> data = {
    {0,1,0,2,1,0,1,3,2,1,2,1},
    {4,2,0,3,2,5}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.trap(data);
    cout << ans << endl;
  } 
  return 0;
}