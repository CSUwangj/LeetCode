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
    for(int mid = 0; mid <= end;) {
      if(nums[mid] == 0) {
        swap(nums[mid], nums[begin]);
        begin += 1;
        mid += 1;
      } else if(nums[mid] == 2) {
        swap(nums[mid], nums[end]);
        end -= 1;
      } else {
        mid += 1;
      }
    }
  }
};

// Accepted
// 87/87 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.85 % of cpp submissions (8.3 MB)
// @lc code=end

