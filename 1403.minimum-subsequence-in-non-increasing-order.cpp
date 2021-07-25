/*
 * @lc app=leetcode id=1403 lang=cpp
 *
 * [1403] Minimum Subsequence in Non-Increasing Order
 */

// @lc code=start
class Solution {
public:
  vector<int> minSubsequence(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    sort(nums.begin(), nums.end(), greater<int>());
    int cur = 0;
    for(int i = 0; i < nums.size(); ++i) {
      if(cur * 2 > sum) {
        nums.resize(i);
        return nums;
      }
      cur += nums[i];
    }
    return nums;
  }
};
// @lc code=end

