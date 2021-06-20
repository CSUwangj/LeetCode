/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 */

// @lc code=start
class Solution {
public:
  int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    int start = -1;
    int len = nums.size();
    int answer = 0;
    while(start < len) {
      while(start < len - 1 && nums[start + 1] > right) start += 1;
      int end = start + 1;
      int preStart = start;
      while(end < len && nums[end] <= right) end += 1;
      for(int i = start + 1; i < end; ++i) {
        if(nums[i] >= left && nums[i] <= right) {
          answer += (i - preStart) * (end - i);
          preStart = i;
        }
      }
      start = end;
    }
    return answer;
  }
};
// @lc code=end

