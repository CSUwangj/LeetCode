/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int len1;
  int len2;
  int low;
  int high;
  int findCount(vector<int> &nums, int high, int num) {
    int low = 0;
    while(low < high) {
      int mid = (low + high + 1) >> 1;
      if(nums[mid] > num) {
        high = mid - 1;
      } else {
        low = mid;
      }
    }
    return low + (nums[low] <= num);
  }
  double findNthSortedArrays(vector<int>& nums1, vector<int>& nums2, int n) {
    if(nums1.empty()) return nums2[n - 1];
    if(nums2.empty()) return nums1[n - 1];
    int low = this->low;
    int high = this->high;
    while(low < high) {
      int mid = (low + high) >> 1;
      int count = findCount(nums1, len1 - 1, mid) + findCount(nums2, len2 - 1, mid);
      if(count < n) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    low = min(nums1.size() ? nums1.front() : INT_MAX, nums2.size() ? nums2.front() : INT_MAX);
    high = max(nums1.size() ? nums1.back() : INT_MIN, nums2.size() ? nums2.back() : INT_MIN);
    len1 = nums1.size();
    len2 = nums2.size();
    pair<int, int> target = {(len1 + len2 + 1) / 2, (len1 + len2 + 2) / 2};
    return (findNthSortedArrays(nums1, nums2, target.first) + findNthSortedArrays(nums1, nums2, target.second)) / 2.0;
  }
};

// Accepted
// 2094/2094 cases passed (60 ms)
// Your runtime beats 21.29 % of cpp submissions
// Your memory usage beats 42.97 % of cpp submissions (89.5 MB)
// @lc code=end
