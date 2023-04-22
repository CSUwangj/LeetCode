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

    for(const auto &connection : connections) {
      neighbors[connection[0]].push_back(connection[1]);
      neighbors[connection[1]].push_back(connection[0]);
    }

    vector<int> vis(n);
    queue<int> q;
    vis[0] = 1;
    q.push(0);
    while(q.size()) {
      int cur = q.front();
      q.pop();
      for(auto next : neighbors[cur]) {
        if(vis[next]) continue;
        q.push(next);
        vis[next] = vis[cur] + 1;
      }
    }

    int answer = 0;
    for(const auto &connection : connections) {
      answer += vis[connection[0]] < vis[connection[1]];
    }

    return answer;
  }
};

// Accepted
// 76/76 cases passed (372 ms)
// Your runtime beats 76.48 % of cpp submissions
// Your memory usage beats 95.28 % of cpp submissions (99.7 MB)
// @lc code=end
