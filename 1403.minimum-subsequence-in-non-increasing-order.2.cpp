/*
 * @lc app=leetcode id=1403 lang=cpp
 *
 * [1403] Minimum Subsequence in Non-Increasing Order
 */

// @lc code=start
class Solution {
public:
  vector<int> minSubsequence(vector<int>& nums) {
    int len = nums.size();
    priority_queue<int> pq;
    int sum = 0;
    for(int i = 0; i < nums.size(); ++i) {
      pq.push(nums[i]);
      sum += nums[i];
    }
    int cur = 0;
    vector<int> answer;
    while(cur <= sum) {
      answer.push_back(pq.top());
      pq.pop();
      cur += answer.back();
      sum -= answer.back();
    }

    return answer;
  }
};
// @lc code=end

