/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start
class Solution {
  vector<vector<int>> neighbors;
  vector<int> num;
  vector<int> low;
  int count = 0;
  void init(int n, vector<vector<int>>& connections) {
    num.resize(n);
    low.resize(n);
    neighbors.resize(n);
    for(auto &edge : connections) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }
  }
  void tarjan(int u, int father, vector<vector<int>> &answer) {
    low[u] = num[u] = ++count;
    for(auto child : neighbors[u]) {
      if(child == father) continue;
      if(!num[child]) {
        tarjan(child, u, answer);
        low[u] = min(low[u], low[child]);
        if(low[child] > num[u]) {
          answer.push_back({u, child});
        }
      } else if (num[child] < num[u]) {
        low[u] = min(low[u], num[child]);
      }
    }
  }
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    init(n, connections);
    vector<vector<int>> answer;
    tarjan(0, 0, answer);
    return answer;
  }
};

// Accepted
// 17/17 cases passed (794 ms)
// Your runtime beats 62.32 % of cpp submissions
// Your memory usage beats 89.75 % of cpp submissions (165.4 MB)
// @lc code=end

