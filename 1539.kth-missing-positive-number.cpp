/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    int pos = 0;
    int prev = 0;
    arr.push_back(INT_MAX);
    while(k) {
      while(arr[pos] - prev == 1) {
        prev = arr[pos];
        pos += 1;
      }
      if(prev + k < arr[pos]) return prev+k;
      else {
        k -= arr[pos] - prev - 1;
        prev = arr[pos];
        pos += 1;
      }
    }
    return -1;
  }
};

// Accepted
// 84/84 cases passed (9 ms)
// Your runtime beats 33.58 % of cpp submissions
// Your memory usage beats 73.33 % of cpp submissions (9.6 MB)
// @lc code=end

