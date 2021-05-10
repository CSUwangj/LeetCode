/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 */

// @lc code=start
class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    int len = nums.size();
    int addCount = 0;
    int minusCount = 0;
    vector<int> copies = nums;
    for(int i = 0; i < len - 1; ++i) {
      if(nums[i] > nums[i + 1]) {
        nums[i + 1] = nums[i];
        addCount += 1;
      }
    }
    for(int i = len - 1; i > 0; --i) {
      if(copies[i] < copies[i - 1]) {
        copies[i - 1] = copies[i];
        minusCount += 1;
      }
    }
    return addCount < 2 || minusCount < 2;
  }
};
// @lc code=end

