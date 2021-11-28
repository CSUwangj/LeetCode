/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
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
  int searchInsert(vector<int>& nums, int target) {
    int begin = 0, end = nums.size();
    nums.push_back(INT_MAX);
    while(begin < end) {
      int mid = (begin + end) >> 1;
      if(nums[mid] < target) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    return begin;
  }
};

// Accepted
// 64/64 cases passed (3 ms)
// Your runtime beats 84.06 % of cpp submissions
// Your memory usage beats 72.14 % of cpp submissions (9.7 MB)
// @lc code=end