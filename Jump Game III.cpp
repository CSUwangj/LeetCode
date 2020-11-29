// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
    vector<bool> visited;
    bool dfs(vector<int> &arr, int current) {
        cout << current << endl;
        if(visited[current]) return false;
        if(arr[current] == 0) return true;
        visited[current] = true;
        int farther = current + arr[current];
        int near = current - arr[current];
        if(farther < arr.size() && dfs(arr, farther)) return true;
        cout << "1: " << current << endl;
        if(near >= 0 && dfs(arr, near)) return true;
        cout << "2: " << current << endl;
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        visited = vector<bool>(arr.size(), false);
        return dfs(arr, start);
    }
};

int main() {
  vector<pair<vector<int>, int>> data = {
    {{4,2,3,0,3,1,2}, 0}
  };
  for(auto &[arr, n]: data) {
    auto sol = Solution();
    auto ans = sol.canReach(arr, n);
    cout << ans << endl;
  } 
  return 0;
}