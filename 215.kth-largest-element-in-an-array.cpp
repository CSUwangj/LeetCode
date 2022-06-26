/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
  int KthLargest(vector<int>& nums, int begin, int len, int k) {
    if(len <= 1) return nums[begin];
    const int pivot = nums[begin + rand()%len];
    int front = begin, index = begin, back = begin+len;
    while(index < back) {
      if(nums[index] < pivot) {
        swap(nums[index], nums[front]);
        index += 1;
        front += 1;
      } else if(nums[index] > pivot) {
        back -= 1;
        swap(nums[index], nums[back]);
      } else {
        index += 1;
      }
    }
    cout << endl;
    if(front >= k) return KthLargest(nums, begin, front-begin, k);
    else if (back < k) return KthLargest(nums, back, begin+len-back, k);
    return pivot;
  }
public:
  int findKthLargest(vector<int>& nums, int k) {
    int len = nums.size();
    return KthLargest(nums, 0, len, len-k+1);
  }
};

// Accepted
// 32/32 cases passed (7 ms)
// Your runtime beats 90.68 % of cpp submissions
// Your memory usage beats 61.91 % of cpp submissions (10.1 MB)
// @lc code=end

