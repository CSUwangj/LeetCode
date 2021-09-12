/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution {
public:
  int dominantIndex(vector<int>& nums) {
    int max[2] = {};
    int answer = -1;
    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i] > max[0]) {
        max[1] = max[0];
        max[0] = nums[i];
        answer = i;
      } else if(nums[i] > max[1]) {
        max[1] = nums[i];
      }
    }
    return (max[0] >= max[1] * 2) ? answer : -1;
  }
};

// Accepted
// 232/232 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 69.27 % of cpp submissions (10.8 MB)
// @lc code=end

