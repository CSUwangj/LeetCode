/*
 * @lc app=leetcode id=1480 lang=cpp
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution {
public:
  vector<int> runningSum(vector<int>& nums) {
    int len = nums.size();
    for(int i = 1; i < len; ++i) nums[i] += nums[i - 1];
    return nums;
  }
};

// Accepted
// 53/53 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 38.06 % of cpp submissions (8.6 MB)
// @lc code=end

