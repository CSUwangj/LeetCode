/*
 * @lc app=leetcode id=2359 lang=cpp
 *
 * [2359] Find Closest Node to Given Two Nodes
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
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    vector<int> distance(edges.size(), INT_MAX);
    vector<bool> visits(edges.size());

    int dis = 0;
    int cur = node1;
    // cout << node1 << '\n' << endl;
    while(cur != -1 && !visits[cur]) {
      // cout << cur << ' ' << dis << endl;
      visits[cur] = true;
      distance[cur] = dis;
      dis += 1;
      cur = edges[cur];
    }

    fill(visits.begin(), visits.end(), false);
    int maxDistance = INT_MAX;
    int answer = -1;
    cur = node2;
    // cout << node2 << '\n' << endl;
    dis = 0;
    while(cur != -1 && !visits[cur]) {
      // cout << cur << ' ' << dis << endl;
      visits[cur] = true;
      if(maxDistance > max(dis, distance[cur]) || (maxDistance == max(dis, distance[cur]) && answer > cur)) {
        maxDistance = max(dis, distance[cur]);
        answer = cur;
      }
      dis += 1;
      cur = edges[cur];
    }

    return answer;
  }
};

// Accepted
// 77/77 cases passed (165 ms)
// Your runtime beats 96.4 % of cpp submissions
// Your memory usage beats 97.78 % of cpp submissions (93.5 MB)
// @lc code=end

