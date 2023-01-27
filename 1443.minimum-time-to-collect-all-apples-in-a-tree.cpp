/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */

// @lc code=start
class Solution {
  vector<bool> hasApple;
  vector<int> parent;
  vector<vector<int>> neighbors;
  
  bool constructTree(int current, int parent, vector<bool>& isApple) {
    bool hasApple = isApple[current];
    this->parent[current] = parent;
    for(auto next : neighbors[current]) {
      if(next == parent) continue;
      hasApple = constructTree(next, current, isApple) || hasApple;
    }
    this->hasApple[current] = hasApple;
    return hasApple;
  }
public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& isApple) {
    hasApple.resize(n);
    neighbors.resize(n);
    parent.resize(n);
    for(const auto &edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }
    constructTree(0, -1, isApple);
    if(!hasApple[0]) return 0;
    queue<int> q;
    q.push(0);
    int answer = 0;
    while(q.size()) {
      int current = q.front();
      q.pop();
      for(auto next : neighbors[current]) {
        if(next == parent[current]) continue;
        if(!hasApple[next]) continue;
        answer += 2;
        q.push(next);
      }
    }
    return answer;
  }
};

// Accepted
// 55/55 cases passed (206 ms)
// Your runtime beats 73.15 % of cpp submissions
// Your memory usage beats 50 % of cpp submissions (61.4 MB)
// @lc code=end

