#include<bits/stdc++.h>

using namespace std;

class Solution {
  int groupDegree[10] = {};
  int degree[10] = {};
  vector<int> children[10];
  vector<int> groupChildren[10];
  vector<int> items[10];
public:
  vector<int> sortItems(int n, int m, vector<int> group, vector<vector<int>> beforeItems) {
    // init
    for(int i = 0; i < n; ++i) {
      if(group[i] == -1) group[i] = m++;
      items[group[i]].push_back(i);
    }
    for(int i = 0; i < n; ++i) {
      for(auto p : beforeItems[i]) {
        children[p].push_back(i);
        degree[i] += 1;
        if(group[p] != group[i]) {
          groupDegree[group[i]] += 1;
          groupChildren[p].push_back(group[i]);
        }
      }
    }

    // topological sort for group
    vector<int> groupOrder;
    queue<int> q;
    for(int i = 0; i < m; ++i) {
      if(!groupDegree[i]) q.push(i);
    }
    while(q.size()) {
      int cur = q.front();
      q.pop();
      groupOrder.push_back(cur);
      for(auto c : groupChildren[cur]) {
        groupDegree[c] -= 1;
        if(!groupDegree[c]) q.push(c);
      }
    }
    cout << groupOrder << endl;
    if(groupOrder.size() != m) return {};

    // sort items
    vector<int> answer;
    for(auto g : groupOrder) {
      int sz = answer.size();
      for(auto item : items[g]) {
        if(!degree[item]) q.push(item);
      }
      while(q.size()) {
        int cur = q.front();
        q.pop();
        answer.push_back(cur);
        for(auto c : children[cur]) {
          degree[c] -= 1;
          if(group[c] == group[cur] && !degree[c]) {
            q.push(c);
          }
        }
      }
      if(answer.size() - sz != items[g].size()) return {};
    }

    return answer;
  }
};

int main() {
    Solution a;
    cout << a.sortItems(8, 2, {-1,-1,1,0,0,1,0,-1}, {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}}) << endl;
    return 0;
}