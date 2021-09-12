/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
  int findMin(vector<int>& nums) {
    int len = nums.size();
    int low = 0;
    int high = len - 1;
    while(low < high && nums[low] > nums[high]) {
      int mid = (low + high) / 2;
      if(nums[mid] >= nums[low]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[low];
  }
};

// Accepted
// 150/150 cases passed (6 ms)
// Your runtime beats 9.85 % of cpp submissions
// Your memory usage beats 70.46 % of cpp submissions (10.1 MB)
// @lc code=end

