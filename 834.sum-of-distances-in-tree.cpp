/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  vector<int> dp, children, answer;
  vector<vector<int>> neighbors;
  
  void init(int N, vector<vector<int>>& edges) {
    dp.resize(N);
    children.resize(N, 1);
    answer.resize(N);
    neighbors.resize(N);
    
    for(auto &edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }
  }
  
  void initDP(int current, int parent) {
    for(auto neighbor : neighbors[current]) {
      if(neighbor == parent) continue;
      
      initDP(neighbor, current);
      children[current] += children[neighbor];
      dp[current] += children[neighbor] + dp[neighbor];
    }
  }
  
  void swapRootDP(int current, int parent) {
    answer[current] = dp[current];
    
    for(auto neighbor : neighbors[current]) {
      if(neighbor == parent) continue;
      
      dp[current] -= children[neighbor] + dp[neighbor];
      children[current] -= children[neighbor];
      dp[neighbor] += dp[current] + children[current];
      children[neighbor] += children[current];
      
      swapRootDP(neighbor, current);
      dp[neighbor] -= dp[current] + children[current];
      children[neighbor] -= children[current];
      dp[current] += children[neighbor] + dp[neighbor];
      children[current] += children[neighbor];
    }
  }
public:
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    init(N, edges);
    initDP(0, -1);
    swapRootDP(0, -1);
    return move(answer);
  }
};

// Accepted
// 73/73 cases passed (251 ms)
// Your runtime beats 97.75 % of cpp submissions
// Your memory usage beats 66.29 % of cpp submissions (87.5 MB)
// @lc code=end

