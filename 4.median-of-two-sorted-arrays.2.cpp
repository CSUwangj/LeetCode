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
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size()) swap(nums1, nums2);
    int len1 = nums1.size();
    int len2 = nums2.size();
    int left = 0;
    int right = len1;
    int total = len1 + len2 + 1;
    bool even = (len1 + len2 + 1) & 1;
    pair<int, int> median;
    while(left <= right) {
      int first = (left + right) / 2;
      int second = total / 2 - first;
      int leftFirst = first ? nums1[first - 1] :  INT_MIN;
      int leftSecond = second ? nums2[second - 1] : INT_MIN;
      int rightFirst = first != len1 ? nums1[first] : INT_MAX;
      int rightSecond = second != len2 ? nums2[second] : INT_MAX;
      if(leftFirst <= rightSecond) {
        median = {max(leftFirst, leftSecond), min(rightFirst, rightSecond)};
        left += 1;
      } else {
        right -= 1;
      }
    } 
    return even ? (median.first + median.second) / 2.0 : median.first;
  }
};

// Accepted
// 2094/2094 cases passed (73 ms)
// Your runtime beats 11.93 % of cpp submissions
// Your memory usage beats 59.58 % of cpp submissions (89.3 MB)
// @lc code=end
