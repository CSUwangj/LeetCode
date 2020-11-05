// Copyright 2020 <CSUwangj@protonmail.com>
#include<bits/stdc++.h>
#define LL int64
#define mk(a, b) make_pair(a, b)
#define ULL uint64
#define mem(a, n) memset(a, n, sizeof(a))
#define lowbit(x) ((x)&(-x))
using namespace std;

class Solution {
  vector<vector<int>> neighbors;
  vector<bool> visited;
  map<int, int> previous_node; 
  int max_length;
  int farthest_node;

  void add_neightbors(vector<vector<int>>& edges) {
    for(auto &edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }
  }

  void find_farthest_node(int cur_node, int cur_length) {
    visited[cur_node] = true;
    if(cur_length > max_length) {
      max_length = cur_length;
      farthest_node = cur_node;
    }
    for(auto neighbor : neighbors[cur_node]) {
      if(!visited[neighbor]) {
        previous_node[neighbor] = cur_node;
        find_farthest_node(neighbor, cur_length+1);
      }
    }
  }
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n == 1) return vector<int>{0};

    neighbors = vector<vector<int>>(n, vector<int>());
    visited = vector<bool>(n);
    add_neightbors(edges);

    fill(visited.begin(), visited.end(), false);
    find_farthest_node(0, 0);

    int far_node = farthest_node;
    max_length = 0;

    fill(visited.begin(), visited.end(), false);
    find_farthest_node(far_node, 0);
    cout << max_length << ' ' << far_node << ' ' << farthest_node << endl;

    int mid_length = max_length / 2, cur_node = farthest_node;
    set<int> ans;
    for(int i = 0; i <= max_length; ++i) {
      cout << cur_node << endl;
      if(i == mid_length || (max_length-i) == mid_length) {
        ans.insert(cur_node);
      }
      cur_node = previous_node[cur_node];
    }

    vector<int> answer;
    copy(ans.begin(), ans.end(), back_inserter(answer));
    return answer;
  }
};

int main() {
  vector<tuple<int, vector<vector<int>>>> data = {
    {6, {{3,0},{3,1},{3,2},{3,4},{5,4}}},
    {4, {{1,0},{1,2},{1,3}}},
    {2, {{0,1}}}
  };
  for(auto &data: data) {
    auto sol = Solution();
    auto [n, edges] = data;
    auto ans = sol.findMinHeightTrees(n, edges);
    cout << ans.size() << endl;
  } 
  return 0;
}