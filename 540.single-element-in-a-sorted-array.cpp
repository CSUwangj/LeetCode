/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
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
  int singleNonDuplicate(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    while(low < high - 1) {
      int mid = (low + high) >> 1;
      mid ^= (mid & 1);
      if(nums[mid] == nums[mid + 1]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[high];
  }
};

// Accepted
// 15/15 cases passed (25 ms)
// Your runtime beats 82.58 % of cpp submissions
// Your memory usage beats 16.37 % of cpp submissions (22.4 MB)
// @lc code=end
