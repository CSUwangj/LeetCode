/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    for(auto stone : stones) {
      pq.push(stone);
    }
    while(pq.size() > 1) {
      auto t = pq.top();
      pq.pop();
      auto s = pq.top();
      pq.pop();
      if(t > s) {
        pq.push(t - s);
      }
    }
    return pq.size() ? pq.top() : 0;
  }
};

// Accepted
// 70/70 cases passed (4 ms)
// Your runtime beats 37.54 % of cpp submissions
// Your memory usage beats 78.96 % of cpp submissions (7.6 MB)
// @lc code=end
