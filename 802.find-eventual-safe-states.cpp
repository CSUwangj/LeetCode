/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
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
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int len = graph.size();
    vector<vector<int>> reverseGraph(len);
    vector<int> degree(len);
    for(int i = 0; i < len; ++i) {
      for(auto next : graph[i]) {
        reverseGraph[next].push_back(i);
        degree[i] += 1;
      }
    }

    queue<int> q;
    vector<int> answer;
    for(int i = 0; i < len; ++i) {
      if(!degree[i]) {
        q.push(i);
      }
    }

    while(q.size()) {
      int current = q.front();
      q.pop();
      answer.push_back(current);
      for(auto next : reverseGraph[current]) {
        degree[next] -= 1;
        if(!degree[next]) {
          q.push(next);
        }
      }
    }
    sort(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 112/112 cases passed (215 ms)
// Your runtime beats 51.35 % of cpp submissions
// Your memory usage beats 22.44 % of cpp submissions (61.5 MB)
// @lc code=end

