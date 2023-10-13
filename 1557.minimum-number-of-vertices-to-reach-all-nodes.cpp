/*
 * @lc app=leetcode id=1557 lang=cpp
 *
 * [1557] Minimum Number of Vertices to Reach All Nodes
 */

// @lc code=start
class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> degree(n);
    for(const auto &edge : edges) {
      degree[edge[1]] += 1;
    }

    vector<int> answer;
    for(int i = 0; i < n; ++i) {
      if(!degree[i]) {
        answer.push_back(i);
      }
    }

    return answer;
  }
};

// Accepted
// 66/66 cases passed (275 ms)
// Your runtime beats 91.92 % of cpp submissions
// Your memory usage beats 89.58 % of cpp submissions (94.2 MB)
// @lc code=end

