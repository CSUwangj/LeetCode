/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int len = nums.size();
    for(auto &n : nums) {
      if(n < 1) n = INT_MAX;
    }
    for(auto n : nums) {
      n = abs(n);
      if(n > len) continue;
      if(nums[n - 1] > 0) nums[n - 1] = -nums[n - 1];
    }
    for(int i = 0; i < len; ++i) {
      if(nums[i] > 0) return i + 1;
    }
    return len + 1;
  }
};

// Accepted
// 173/173 cases passed (148 ms)
// Your runtime beats 76.92 % of cpp submissions
// Your memory usage beats 40.04 % of cpp submissions (83.1 MB)
// @lc code=end
