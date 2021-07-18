/*
 * @lc app=leetcode id=1203 lang=cpp
 *
 * [1203] Sort Items by Groups Respecting Dependencies
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  vector<int> groupDegree;
  int degree[30000];
  vector<vector<int>> children;
  vector<vector<int>> groupChildren;
  vector<vector<int>> items;
public:
  vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    // init
    children.resize(n);
    items.resize(m);
    for(int i = 0; i < n; ++i) {
      if(group[i] == -1) {
        group[i] = m++;
        items.push_back({});
      }
      items[group[i]].push_back(i);
    }
    groupChildren.resize(m);
    groupDegree.resize(m);
    for(int i = 0; i < n; ++i) {
      for(auto p : beforeItems[i]) {
        children[p].push_back(i);
        degree[i] += 1;
        if(group[p] != group[i]) {
          groupDegree[group[i]] += 1;
          groupChildren[group[p]].push_back(group[i]);
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
    // cout << groupOrder << endl;
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

// Accepted
// 17/17 cases passed (60 ms)
// Your runtime beats 97.68 % of cpp submissions
// Your memory usage beats 70.86 % of cpp submissions (45.2 MB)
// @lc code=end

