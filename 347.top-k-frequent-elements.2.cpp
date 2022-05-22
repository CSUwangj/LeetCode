/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
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
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for(auto n : nums) {
      count[n] += 1;
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(auto [n, c] : count) {
      pq.push({c, n});
      if(pq.size() > k) pq.pop();
    }
    vector<int> answer;
    answer.reserve(k);
    while(pq.size()) {
      answer.push_back(pq.top().second);
      pq.pop();
    }
    return answer;
  }
};

// Accepted
// 21/21 cases passed (12 ms)
// Your runtime beats 95.02 % of cpp submissions
// Your memory usage beats 41.62 % of cpp submissions (13.7 MB)
// @lc code=end
