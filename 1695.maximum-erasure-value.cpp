/*
 * @lc app=leetcode id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */

// @lc code=start
class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    bool vis[10001] = {};
    int sum = 0;
    int start = 0;
    int len = nums.size();
    int answer = 0;
    for(int end = 0; end < len; ++end) {
      while(vis[nums[end]]) {
        vis[nums[start]] = false;
        sum -= nums[start];
        start += 1;
      }
      vis[nums[end]] = true;
      sum += nums[end];
      answer = max(sum, answer);
    }
    return answer;
  }
};
// @lc code=end
