/*
 * @lc app=leetcode id=915 lang=cpp
 *
 * [915] Partition Array into Disjoint Intervals
 */

// @lc code=start
int mmax[30000];
int mmin[30000];
class Solution {
public:
  int partitionDisjoint(vector<int>& nums) {
    int len = nums.size();
    mmax[0] = nums[0];
    mmin[len - 1] = nums[len - 1];
    for(int i = 1; i < len; ++i) {
      mmax[i] = max(mmax[i - 1], nums[i]);
      mmin[len - 1 - i] = min(mmin[len - i], nums[len - 1 - i]);
    }
    for(int i = 1; i < len; ++i) {
      if(mmax[i - 1] <= mmin[i]) return i;
    }
    return -1;
  }
};
// @lc code=end

