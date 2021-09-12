/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
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
    int len = nums.size();
    int low = 0;
    int high = len - 1;
    while(nums[low] > nums[high]) {
      int mid = (low + high) >> 1;
      if(nums[mid] >= nums[low]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[low];
  }
};

// Accepted
// 150/150 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 23.47 % of cpp submissions (10.4 MB)
// @lc code=end

