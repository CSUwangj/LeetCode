/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    return unique(nums.begin(), nums.end()) - nums.begin();
  }
};

// Accepted
// 361/361 cases passed (36 ms)
// Your runtime beats 18.18 % of cpp submissions
// Your memory usage beats 37.3 % of cpp submissions (18.5 MB)
// @lc code=end

