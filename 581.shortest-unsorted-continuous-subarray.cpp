/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int len = nums.size();
    int wrongLess = -1;
    for(int i = 1; i < len; ++i) {
      if(nums[i] < nums[i - 1]) {
        wrongLess = i - 1;
        break;
      }
    }
    if(wrongLess == -1) return 0;
    int wrongGreater = -1;
    for(int i = len - 2; i >= 0; --i) {
      if(nums[i] > nums[i + 1]) {
        wrongGreater = i + 1;
        break;
      }
    }
    int minPos = wrongLess;
    int maxPos = wrongGreater;
    for(int i = min(wrongLess, wrongGreater); i <= max(wrongLess, wrongGreater); ++i) {
      if(nums[i] < nums[minPos]) minPos = i;
      if(nums[i] > nums[maxPos]) maxPos = i;
    }
    int begin = 0;
    while(nums[begin] <= nums[minPos]) begin += 1;
    int end = len - 1;
    while(nums[end] >= nums[maxPos]) end -= 1;
    return end - begin + 1;
  }
};

// Accepted
// 307/307 cases passed (26 ms)
// Your runtime beats 94.24 % of cpp submissions
// Your memory usage beats 68.9 % of cpp submissions (26.6 MB)
// @lc code=end

