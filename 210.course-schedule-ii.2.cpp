/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> edges(numCourses);
    vector<int> degree(numCourses);

    for(auto &prerequisite : prerequisites) {
      edges[prerequisite[1]].push_back(prerequisite[0]);
      degree[prerequisite[0]] += 1;
    }

    queue<int> q;
    for(int i = 0; i < numCourses; ++i) {
      if(!degree[i]) q.push(i);
    }

    vector<int> answer;
    while(q.size()) {
      auto cur = q.front();
      q.pop();
      answer.push_back(cur);
      for(auto next : edges[cur]) {
        degree[next] -= 1;
        if(!degree[next]) {
          q.push(next);
        }
      }
    }
    if(answer.size() < numCourses) return {};
    return answer;
  }
};

// Accepted
// 44/44 cases passed (16 ms)
// Your runtime beats 93.62 % of cpp submissions
// Your memory usage beats 87.92 % of cpp submissions (13.3 MB)
// @lc code=end
