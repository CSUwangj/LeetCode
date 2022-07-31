/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int len = nums.size();
    if(!len) return{-1, -1};
    int begin = 0;
    int end = len - 1;
    while(begin < end) {
      int mid = (begin + end) >> 1;
      if(nums[mid] < target) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    if(nums[begin] != target) return {-1, -1};
    int left = begin;
    begin = 0;
    end = len - 1;
    while(begin < end) {
      int mid = (begin + end + 1) >> 1;
      if(nums[mid] > target) {
        end = mid - 1;
      } else {
        begin = mid;
      }
    }
    return {left, begin};
  }
};

// Accepted
// 88/88 cases passed (13 ms)
// Your runtime beats 48.91 % of cpp submissions
// Your memory usage beats 83.66 % of cpp submissions (13.6 MB)
// @lc code=end

