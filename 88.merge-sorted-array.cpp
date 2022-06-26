/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    while(m && n) {
      if(nums1[m-1] > nums2[n-1]) {
        nums1[m+n-1] = nums1[m-1];
        m -= 1;
      } else {
        nums1[m+n-1] = nums2[n-1];
        n -= 1;
      }
    }
    while(n) {
      nums1[n-1] = nums2[n-1];
      n -= 1;   
    }
  }
};

// Accepted
// 59/59 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.57 % of cpp submissions (9.1 MB)
// @lc code=end

