/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
  void sortColors(vector<int>& nums) {
    int begin = 0;
    int end = nums.size() - 1;
    while(begin < end && (nums[begin] == 0 || nums[begin] == 2 || nums[end] == 0 || nums[end] == 2)) {
      while(begin < end && nums[begin] == 0) {
        begin += 1;
      }
      while(begin < end && nums[end] == 2) {
        end -= 1;
      }
      if(begin >= end) break;
      if((nums[begin] == 2 || nums[end] == 0)) {
        swap(nums[begin], nums[end]);
        if(nums[end] == 0) begin += 1;
        if(nums[begin] == 2) end -= 1;
      }
    }
    int mid = begin + 1;
    while(mid <= end) {
      while(mid <= end && nums[mid] == 1) mid += 1;
      if(mid > end) break;
      if(nums[mid] == 0) {
        swap(nums[mid], nums[begin]);
        begin += 1;
      } else {
        swap(nums[mid], nums[end]);
        end -= 1;
      }
    }
  }
};

// Accepted
// 87/87 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.85 % of cpp submissions (8.3 MB)
// @lc code=end

