/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
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
  int findMin(vector<int>& nums) {
    return *min_element(nums.begin(), nums.end());
   }
};

// Accepted
// 192/192 cases passed (11 ms)
// Your runtime beats 22.47 % of cpp submissions
// Your memory usage beats 11.51 % of cpp submissions (12.3 MB)
// @lc code=end

