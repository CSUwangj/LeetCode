/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums;
  }
};

// Accepted
// 19/19 cases passed (133 ms)
// Your runtime beats 86.49 % of cpp submissions
// Your memory usage beats 56.18 % of cpp submissions (61.3 MB)
// @lc code=end

