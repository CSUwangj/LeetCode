/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  using pi = pair<int, int>;
  vector<vector<pi>> nextJump;
  vector<int> delays;
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    nextJump.resize(n);
    delays.resize(n);
    fill(delays.begin(), delays.end(), -1);
    for(const auto &time : times) {
      nextJump[time[0] - 1].push_back({time[1] - 1, time[2]});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, k - 1});
    int answer = 0;
    for(int _node = 0; _node < n; ++_node) {
      while(pq.size() && delays[pq.top().second] != -1) {
        pq.pop();
      }
      if(pq.empty()) return -1;
      auto [delay, node] = pq.top();
      // cout << "Node " << node << ": " << delay << endl; 
      pq.pop();
      delays[node] = delay;
      answer = delay;
      for(const auto &[next, addDelay] : nextJump[node]) {
        if(delays[next] != -1) continue;
        pq.push({delay + addDelay, next});
      }
    }
    return answer;
  }
};

// Accepted
// 52/52 cases passed (126 ms)
// Your runtime beats 84.67 % of cpp submissions
// Your memory usage beats 50.01 % of cpp submissions (41.2 MB)
// @lc code=end
