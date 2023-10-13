/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int len = nums.size();
    int begin = 0;
    int end = len - 1;
    int mid;
    while (nums[begin] > nums[end]) {
      mid = (begin + end) / 2;
      if (nums[mid] >= nums[begin]) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    int pivot = begin;
    begin = 0;
    end = len;
    while (begin < end) {
      mid = (begin + end) / 2;
      if (nums[(mid + pivot) % len] < target) begin = mid + 1;
      else end = mid;
    }
    return nums[(begin + pivot) % len] == target ? (begin + pivot) % len : -1;
  }
};

// Accepted
// 195/195 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 13.7 % of cpp submissions (11.1 MB)
// @lc code=end

