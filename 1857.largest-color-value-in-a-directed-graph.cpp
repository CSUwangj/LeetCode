/*
 * @lc app=leetcode id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 */

// @lc code=start
class Solution {
  using T = array<int, 26>;
public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    vector<vector<int>> neighbors(colors.size());
    vector<int> indegree(colors.size());

    for(const auto &edge : edges) {
      neighbors[edge[0]].push_back(edge[1]);
      indegree[edge[1]] += 1;
    }

    vector<T> count(colors.size(), T{});
    queue<int> q;
    for(int i = 0; i < colors.size(); ++i) {
      if(!indegree[i]) {
        q.push(i);
        count[i][colors[i] - 'a'] = 1;
      }
    }

    int answer = 0;
    int seen = 0;
    while(q.size()) {
      int current = q.front();
      q.pop();
      seen += 1;
      answer = max(answer, *max_element(count[current].begin(), count[current].end()));

      for(auto neighbor : neighbors[current]) {
        for(int i = 0; i < 26; ++i) {
          count[neighbor][i] = max(count[neighbor][i], count[current][i] + (i == colors[neighbor] - 'a'));
        }
        indegree[neighbor] -= 1;
        if(!indegree[neighbor]) {
          q.push(neighbor);
        }
      }
    }

    if(seen < colors.size()) return -1;
    return answer;
  }
};

// Accepted
// 83/83 cases passed (530 ms)
// Your runtime beats 93.59 % of cpp submissions
// Your memory usage beats 90.6 % of cpp submissions (143.3 MB)
// @lc code=end

