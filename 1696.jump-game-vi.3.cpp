/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 */

// @lc code=start
class Solution {
public:
  int maxResult(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    int len = nums.size();
    int answer = nums[0];
    pq.push({nums[0], 0});
    for(int i = 1; i < len; ++i) {
      while(pq.top().second + k < i) pq.pop();
      answer = pq.top().first + nums[i];
      pq.push({answer, i});
    }
    return answer;
  }
};

// Accepted
// 65/65 cases passed (292 ms)
// Your runtime beats 24.47 % of cpp submissions
// Your memory usage beats 35.8 % of cpp submissions (90.4 MB)
// @lc code=end

