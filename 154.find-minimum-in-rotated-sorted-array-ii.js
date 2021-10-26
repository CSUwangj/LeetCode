/*
 * @lc app=leetcode id=154 lang=javascript
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
  if (nums[0] < nums[nums.length-1]) return nums[0];
  for (const val of nums) {
    if (val < nums[0]) return val;
  }
  return nums[0];
};

// Accepted
// 192/192 cases passed (99 ms)
// Your runtime beats 34.68 % of javascript submissions
// Your memory usage beats 17.74 % of javascript submissions (40.3 MB)
// @lc code=end

