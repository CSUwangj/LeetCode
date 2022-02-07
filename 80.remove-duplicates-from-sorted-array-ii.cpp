/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    int newLen = 0;
    int pos = 0;
    while(pos < len) {
      swap(nums[pos], nums[newLen]);
      pos += 1;
      newLen += 1;
      if(pos < len && nums[pos] == nums[newLen - 1]) {
        swap(nums[pos], nums[newLen]);
        newLen += 1;
        pos += 1;
        while(pos < len && nums[newLen - 1] == nums[pos]) {
          pos += 1;
        }
      }
    }
    return newLen;
  }
};

// Accepted
// 164/164 cases passed (4 ms)
// Your runtime beats 86.5 % of cpp submissions
// Your memory usage beats 9.46 % of cpp submissions (11 MB)
// @lc code=end
