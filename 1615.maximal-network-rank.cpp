/*
 * @lc app=leetcode id=1615 lang=cpp
 *
 * [1615] Maximal Network Rank
 */

// @lc code=start
class Solution {
  vector<int> degree;
  vector<unordered_set<int>> neighbors;
public:
  int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    degree.resize(n);
    neighbors.resize(n);
    for(auto &road : roads) {
      neighbors[road[0]].insert(road[1]);
      neighbors[road[1]].insert(road[0]);
      degree[road[0]] += 1;
      degree[road[1]] += 1;
    }
    int answer = 0;
    for(int i = 0; i < n-1; ++i) {
      for(int j = i+1; j < n; ++j) {
        int res = degree[i]+degree[j]-neighbors[i].count(j);
        answer = max(answer, res);
      }
    }
    return answer;
  }
};

// Accepted
// 83/83 cases passed (87 ms)
// Your runtime beats 64.87 % of cpp submissions
// Your memory usage beats 31.01 % of cpp submissions (39.2 MB)
// @lc code=end

