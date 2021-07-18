/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int len = nums.size();
    if(len == 1) return 0;
    int start = 0;
    int end = len - 1;
    if(nums[start] > nums[start + 1]) return start;
    if(nums[end] > nums[end - 1]) return end;
    while(start < end) {
      int mid = (start + end) >> 1;
      // cout << start << ' ' << mid << ' ' << end << endl;
      if(nums[mid] > nums[mid + 1] && (!mid || nums[mid] > nums[mid - 1])) return mid;
      if(!mid || nums[mid] > nums[mid - 1]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return start;
  }
};
// @lc code=end

