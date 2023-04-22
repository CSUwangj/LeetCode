/*
 * @lc app=leetcode id=2492 lang=cpp
 *
 * [2492] Minimum Score of a Path Between Two Cities
 */

// @lc code=start
class Solution {
  using pi = pair<int, int>;
public:
  int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<pi>> neighbors(n);
    for(const auto &road : roads) {
      neighbors[road[0] - 1].push_back({road[1] - 1, road[2]});
      neighbors[road[1] - 1].push_back({road[0] - 1, road[2]});
    }
    
    vector<bool> vis(n);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    int answer = INT_MAX;
    while(q.size()) {
      auto pos = q.front();
      q.pop();
      for(const auto &[neighbor, score] : neighbors[pos]) {
        answer = min(answer, score);
        if(vis[neighbor]) continue;
        vis[neighbor] = true;
        q.push(neighbor);
      }
    }

    return answer;
  }
};

// Accepted
// 41/41 cases passed (452 ms)
// Your runtime beats 85.54 % of cpp submissions
// Your memory usage beats 73.39 % of cpp submissions (125.4 MB)
// @lc code=end

