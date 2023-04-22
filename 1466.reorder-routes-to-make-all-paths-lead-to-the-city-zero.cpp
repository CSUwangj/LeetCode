/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution {
public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> neighbors(n);
    set<pair<int, int>> st;

    for(const auto &connection : connections) {
      neighbors[connection[0]].push_back(connection[1]);
      neighbors[connection[1]].push_back(connection[0]);
    }

    vector<bool> vis(n);
    queue<int> q;
    vis[0] = true;
    q.push(0);
    while(q.size()) {
      int cur = q.front();
      q.pop();
      for(auto next : neighbors[cur]) {
        if(vis[next]) continue;
        st.insert({cur, next});
        q.push(next);
        vis[next] = true;
      }
    }

    int answer = 0;
    for(const auto &connection : connections) {
      if(st.count({connection[0], connection[1]})) {
        answer += 1;
      }
    }

    return answer;
  }
};
// @lc code=end
