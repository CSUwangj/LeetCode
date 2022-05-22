/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    int len = nums.size();
    int pos = len - 1;
    
    while(pos && nums[pos] <= nums[pos-1]) --pos;
    if(!pos) {
      reverse(nums.begin(), nums.end());
      return;
    }
    int swapPos = len - 1;
    --pos;
    while(nums[swapPos] <= nums[pos]) swapPos -= 1;
    swap(nums[swapPos], nums[pos]);
    reverse(nums.begin() + pos + 1, nums.end());
  }
};

// Accepted
// 265/265 cases passed (7 ms)
// Your runtime beats 51.84 % of cpp submissions
// Your memory usage beats 93.15 % of cpp submissions (12 MB)
// @lc code=end
