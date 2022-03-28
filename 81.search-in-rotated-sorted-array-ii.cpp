/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
  bool search(vector<int>& nums, int target) {
    if(nums.empty()) return false;
    int offset = 0;
    int len = nums.size();
    for(int i = 1; i < len; ++i) {
      if(nums[i] < nums[i-1]) {
        offset = i;
        break;
      }
    }
    int start = 0, end = nums.size() - 1;
    while(start < end) {
      int mid = (start + end) / 2;
      int pos = (mid + offset) % len;
      if(nums[pos] < target) start = mid + 1;
      else end = mid;
    }
    return nums[(start+offset)%len] == target;
  }
};

// Accepted
// 279/279 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 90.12 % of cpp submissions (13.9 MB)
// @lc code=end
