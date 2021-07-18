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
enum State { INIT, VISTED, STABLE };
class Solution {
  State itemStates[30000];
  State groupStates[30000];
  int groupOrder[30000];
  int count;
  bool itemsTopologicalSort(
    int child,
    vector<int> &group,
    vector<vector<int>> &beforeItems,
    vector<vector<int>> &items,
    vector<vector<int>> &beforeGroups
  ) {
    if(itemStates[child] == State::VISTED) return false;
    itemStates[child] = State::VISTED;
    for(auto parent : beforeItems[child]) {
      if(itemStates[parent] != State::STABLE) {
        if(!itemsTopologicalSort(parent, group, beforeItems, items, beforeGroups)) return false;
      }
      if(group[parent] != group[child]) {
        beforeGroups[group[child]].push_back(group[parent]);
      }
    }
    itemStates[child] = State::STABLE;
    items[group[child]].push_back(child);
    return true;
  }

  bool groupTopologicalSort(
    int child,
    vector<vector<int>> &beforeGroups
  ) {
    if(groupStates[child] == State::VISTED) return false;
    groupStates[child] = State::VISTED;
    for(auto parent : beforeGroups[child]) {
      if(groupStates[parent] != State::STABLE) {
        if(!groupTopologicalSort(parent, beforeGroups)) return false;
      }
    }
    groupStates[child] = State::STABLE;
    groupOrder[count++] = child;
    return true;
  }
public:
  vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>>& beforeItems) {
    // init
    for(int i = 0; i < n; ++i) {
      if(group[i] == -1) group[i] = m++;
    }
    vector<vector<int>> items(m);
    vector<vector<int>> beforeGroups(m);

    bool ok = true;
    for(int i = 0; i < n && ok; ++i) {
      if(itemStates[i] == State::INIT) {
        ok = itemsTopologicalSort(i, group, beforeItems, items, beforeGroups);
      }
    }
    if(!ok) return {};

    for(int i = 0; i < m && ok; ++i) {
      if(groupStates[i] == State::INIT) {
        ok = groupTopologicalSort(i, beforeGroups);
      }
    }
    if(!ok) return {};

    vector<int> answer;
    for(int i = 0; i < count; ++i) {
      int g = groupOrder[i];
      answer.insert(answer.end(), items[g].begin(), items[g].end());
    }
    return answer;
  }
};

// Accepted
// 17/17 cases passed (40 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 97.29 % of cpp submissions (36.3 MB)
// @lc code=end

