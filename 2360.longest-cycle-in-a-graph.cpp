/*
 * @lc app=leetcode id=2360 lang=cpp
 *
 * [2360] Longest Cycle in a Graph
 */

// @lc code=start
class Solution {
public:
  int longestCycle(vector<int>& edges) {
    int n = edges.size();
    if(n < 2) return -1;
    vector<int> degree(n);
    set<int> visit;

    int answer = -1;
    for(int i = 0; i < n; ++i) {
      if(degree[i]) continue;
      int current = i;
      int prev;
      int d = 1;
      visit.clear();
      while(current != -1) {
        if(degree[current] && !visit.count(current)) break;
        if(visit.count(current)) {
          answer = max(answer, degree[prev] - degree[current] + 1);
          break;
        }
        degree[current] = d;
        d += 1;
        visit.insert(current);
        prev = current;
        current = edges[current];
      }
    }

    return answer;
  }
};

// Accepted
// 76/76 cases passed (554 ms)
// Your runtime beats 32.08 % of cpp submissions
// Your memory usage beats 43.72 % of cpp submissions (153.5 MB)
// @lc code=end

