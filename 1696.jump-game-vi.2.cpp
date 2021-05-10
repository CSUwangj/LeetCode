/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 */

// @lc code=start
class Solution {
public:
  int maxResult(vector<int>& nums, int k) {
    deque<int> monoQueue{nums[0]};
    int len = nums.size();
    for(int i = 1; i < min(k, len); ++i) {
      nums[i] += monoQueue.front();
      while(monoQueue.size() && monoQueue.back() < nums[i]) monoQueue.pop_back();
      monoQueue.push_back(nums[i]);
    }
    for(int i = k; i < len; ++i) {
      nums[i] += monoQueue.front();
      while(monoQueue.size() && monoQueue.back() < nums[i]) monoQueue.pop_back();
      if(monoQueue.size() && monoQueue.front() == nums[i - k]) monoQueue.pop_front();
      monoQueue.push_back(nums[i]);
    }
    return nums.back();
  }
};

// Accepted
// 65/65 cases passed (152 ms)
// Your runtime beats 76.39 % of cpp submissions
// Your memory usage beats 79.76 % of cpp submissions (78.3 MB)
// @lc code=end

