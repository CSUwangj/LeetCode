/*
 * @lc app=leetcode id=1203 lang=cpp
 *
 * [1203] Sort Items by Groups Respecting Dependencies
 */

// @lc code=start
template<typename T>
std::ostream& operator<<(std::ostream &out, const std::vector<T> &v) {
  if(v.size() == 0) {
    out << "[]" << std::endl;
    return out;
  }
  out << '[' << v[0];
  for(int i = 1; i < v.size(); ++i) {
    out << ", " << v[i];
  }
  out << ']';
  return out;
}
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
enum State { INIT, VISTED, STABLE };
class Solution {
  vector<State> itemStates;
  vector<State> groupStates;
  vector<int> groupOrder;
  bool itemsTopologicalSort(
    int child,
    vector<int> &group,
    vector<vector<int>> &beforeItems,
    vector<int> *items,
    vector<int> *beforeGroups
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
    vector<int> *beforeGroups
  ) {
    if(groupStates[child] == State::VISTED) return false;
    groupStates[child] = State::VISTED;
    for(auto parent : beforeGroups[child]) {
      if(groupStates[parent] != State::STABLE) {
        if(!groupTopologicalSort(parent, beforeGroups)) return false;
      }
    }
    groupStates[child] = State::STABLE;
    groupOrder.push_back(child);
    return true;
  }
public:
  vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>>& beforeItems) {
    // init
    itemStates.resize(n, State::INIT);
    for(int i = 0; i < n; ++i) {
      if(group[i] == -1) group[i] = m++;
    }
    vector<int> items[m];
    vector<int> beforeGroups[m];

    bool ok = true;
    for(int i = 0; i < n && ok; ++i) {
      if(itemStates[i] == State::INIT) {
        ok = itemsTopologicalSort(i, group, beforeItems, items, beforeGroups);
      }
    }
    if(!ok) return {};

    groupStates.resize(m, State::INIT);
    for(int i = 0; i < m && ok; ++i) {
      if(groupStates[i] == State::INIT) {
        ok = groupTopologicalSort(i, beforeGroups);
      }
    }
    if(!ok) return {};

    vector<int> answer;
    for(auto g : groupOrder) {
      answer.insert(answer.end(), items[g].begin(), items[g].end());
    }
    return answer;
  }
};

// Accepted
// 17/17 cases passed (48 ms)
// Your runtime beats 99.66 % of cpp submissions
// Your memory usage beats 98.31 % of cpp submissions (36 MB)
// @lc code=end

