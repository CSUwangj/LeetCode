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
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<tuple<int, int, int>> points;
    for(auto &building : buildings) {
      points.push_back(make_tuple(building[0], building[1], building[2]));
      points.push_back(make_tuple(building[1], -1, building[2]));
    }
    sort(points.begin(), points.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
      auto [a1, a2, a3] = a;
      auto [b1, b2, b3] = b; 
      return a1 < b1 || (a1 == b1 && (a2 != -1 && b2 == -1));
    });
    vector<vector<int>> answer;
    priority_queue<pair<int, int>> q;
    int currentHeight = 0;
    for(auto [point, rightPoint, height] : points) {
      if(rightPoint == -1) {
        while(q.size() && q.top().second <= point) q.pop();
        int newHeight = q.empty() ? 0 : q.top().first;
        if(newHeight != currentHeight) {
          answer.push_back(vector<int>{point, newHeight});
          currentHeight = newHeight;
        }
      } else {
        if(height > currentHeight) {
          answer.push_back(vector<int>{point, height});
          currentHeight = height;
        }
        q.push(make_pair(height, rightPoint));
      }
    }
    return answer;
  }
};

int main() {
  vector<vector<vector<int>>> data = {
    {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}},
    {{0,2,3},{2,5,3}}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto ans = sol.getSkyline(data);
    cout << '[' ;
    for(auto &p : ans) {
      cout << '[' << p[0] << ", " << p[1] << "], ";
    }
    cout << ']' << endl;
  } 
  return 0;
}