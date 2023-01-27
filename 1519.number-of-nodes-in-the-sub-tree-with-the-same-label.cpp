/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

// @lc code=start
class Solution {
  vector<vector<int>> count;
  vector<vector<int>> neighbors;
  void dfs(int current, int parent, vector<int> &answer, string &labels) {
    for(auto next : neighbors[current]) {
      if(parent == next) continue;
      dfs(next, current, answer, labels);
      for(int i = 0; i < 26; ++i) {
        count[i][current] += count[i][next];
      }
    }
    count[labels[current] - 'a'][current] += 1;
    answer[current] = count[labels[current] - 'a'][current];
  }
public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    neighbors.resize(n);
    count.resize(26, vector<int>(n));
    for(const auto &edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      neighbors[edge[1]].push_back(edge[0]);
    }

    vector<int> answer(n);
    dfs(0, -1, answer, labels);

    return answer;
  }
};

// Accepted
// 59/59 cases passed (595 ms)
// Your runtime beats 82.96 % of cpp submissions
// Your memory usage beats 82.22 % of cpp submissions (181.6 MB)
// @lc code=end

