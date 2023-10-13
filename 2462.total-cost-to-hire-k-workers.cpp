/*
 * @lc app=leetcode id=2462 lang=cpp
 *
 * [2462] Total Cost to Hire K Workers
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
public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    int len = costs.size();
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(int i = 0; i < candidates && i * 2 < len; ++i) {
      pq.push({costs[i], i});
      if(len - 1 - i != i) pq.push({costs[len - 1 - i], len - i - 1});
    }

    int frontPos = candidates;
    int backPos = len - 1 - candidates;
    long long answer = 0;
    while(k--) {
      auto [cost, pos] = pq.top();
      pq.pop();
      answer += cost;
      if(frontPos > backPos) {
        continue;
      }
      if(pos < frontPos) {
        pq.push({costs[frontPos], frontPos});
        frontPos += 1;
      } else {
        pq.push({costs[backPos], backPos});
        backPos -= 1;
      }
    }

    return answer;
  }
};

// Accepted
// 160/160 cases passed (232 ms)
// Your runtime beats 45.42 % of cpp submissions
// Your memory usage beats 46.64 % of cpp submissions (75.3 MB)
// @lc code=end

