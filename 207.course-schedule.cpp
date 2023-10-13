/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> degree(numCourses);
    vector<vector<int>> edges(numCourses);
    for(auto &edge : prerequisites) {
      edges[edge[0]].push_back(edge[1]);
      degree[edge[1]] += 1;
    }
    queue<int> q;
    int answer = 0;
    for(int i = 0; i < numCourses; ++i) {
      if(!degree[i]) {
        answer += 1;
        q.push(i);
      }
    }
    while(q.size()) {
      int cur = q.front();
      q.pop();
      for(auto nxt : edges[cur]) {
        degree[nxt] -= 1;
        if(!degree[nxt]) {
          answer += 1;
          q.push(nxt);
        }
      }
    }
    return answer == numCourses;
  }
};

// Accepted
// 52/52 cases passed (25 ms)
// Your runtime beats 62.83 % of cpp submissions
// Your memory usage beats 83.94 % of cpp submissions (13.2 MB)
// @lc code=end

