/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int degree[15] = {};
    int n = graph.size();
    for(auto &nexts : graph) {
      for(auto next : nexts) {
        degree[next] += 1;
      }
    }
    if(degree[0]) return {};

    queue<int> q;
    vector<vector<int>> result[n];
    q.push(0);
    result[0].push_back({0});

    while(q.size()) {
      int cur = q.front();
      q.pop();
      for(auto next : graph[cur]) {
        for(auto path : result[cur]) {
          path.push_back(next);
          result[next].emplace_back(path);
        }
        degree[next] -= 1;
        if(!degree[next]) {
          q.push(next);
        }
      }
    }
    return result[n - 1];
  }
};

// Accepted
// 30/30 cases passed (28 ms)
// Your runtime beats 33.13 % of cpp submissions
// Your memory usage beats 15.98 % of cpp submissions (18.2 MB)
// @lc code=end
