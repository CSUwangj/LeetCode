/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int pos = 0;
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
      if(nums[i] != val) {
        if(i != pos) nums[pos] = nums[i];
        pos += 1;
      }
    }
    return pos;
  }
};

// Accepted
// 113/113 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.56 % of cpp submissions (8.7 MB)
// @lc code=end
