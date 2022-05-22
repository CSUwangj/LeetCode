/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    for(auto i : nums) {
      i = i > 0 ? i : -i;
      if(nums[i] < 0) return i;
      nums[i] = -nums[i];
    }
    return -1;
  }
};

// Accepted
// 58/58 cases passed (90 ms)
// Your runtime beats 98.15 % of cpp submissions
// Your memory usage beats 99.24 % of cpp submissions (61 MB)
// @lc code=end
