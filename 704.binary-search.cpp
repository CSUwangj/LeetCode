/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
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
  int search(vector<int>& nums, int target) {
    int begin = 0, end = nums.size()-1;
    while(begin < end) {
      int mid = (begin + end) >> 1;
      if(nums[mid] >= target) {
        end = mid;
      } else {
        begin = mid+1;
      }
    }
    return nums[begin]==target?begin:-1;
  }
};

// Accepted
// 47/47 cases passed (28 ms)
// Your runtime beats 98.7 % of cpp submissions
// Your memory usage beats 13.43 % of cpp submissions (27.7 MB)
// @lc code=end
