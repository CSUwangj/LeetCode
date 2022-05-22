/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    int len = graph.size();
    vector<int> type(len, -1);
    int count = 0;
    while(count < len) {
      queue<int> q;
      for(int i = 0; i < len; ++i) {
        if(type[i] != -1) continue;
        q.push(i);
        type[i] = 0;
        count += 1;
        break;
      }
      while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto neighbor : graph[cur]) {
          if(type[neighbor] == type[cur]) return false;
          if(type[neighbor] == (type[cur] ^ 1)) continue;
          q.push(neighbor);
          type[neighbor] = type[cur] ^ 1;
          count += 1;
        }
      }
    }
    return true;
  }
};

// Accepted
// 80/80 cases passed (27 ms)
// Your runtime beats 73.07 % of cpp submissions
// Your memory usage beats 41.19 % of cpp submissions (13.7 MB)
// @lc code=end

