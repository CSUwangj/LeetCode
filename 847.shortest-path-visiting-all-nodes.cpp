/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
pair<int, int> getState(int state) {
  int visited = ((1 << 12) - 1) & state;
  state >>= 12;
  int current;
  for(int i = 0; i < 12; ++i) {
    if((1 << i) & state) current = i;
  }
  return {current, visited};
}
inline constexpr int genState(int current, int visited) {
  return (1 << (current + 12)) | visited;
}
class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int len = graph.size();
    const int TARGET = (1 << len) - 1;
    queue<int> q;
    set<int> states;
    for(int i = 0; i < len; ++i) {
      int state = genState(i, (1 << i));
      q.push(state);
      states.insert(state);
    }
    int answer = 0;
    while(q.size()) {
      int sz = q.size();
      for(int _ = 0; _ < sz; ++_) {
        auto [current, visited] = getState(q.front());
        q.pop();
        if(visited == TARGET) return answer;
        for(auto nxt : graph[current]) {
          int state = genState(nxt, visited | (1 << nxt));
          if(states.count(state))continue;
          states.insert(state);
          q.push(state);
        }
      }
      answer += 1;
    }
    return -1;
  }
};

// Accepted
// 51/51 cases passed (143 ms)
// Your runtime beats 38.12 % of cpp submissions
// Your memory usage beats 54.29 % of cpp submissions (16.9 MB)
// @lc code=end
