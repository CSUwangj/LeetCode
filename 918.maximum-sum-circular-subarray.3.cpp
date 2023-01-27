/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
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
  int maxSubarraySumCircular(vector<int>& nums) {
    int currentMinSum = INT_MAX - 30000;
    int minSum = INT_MAX;
    int currentMaxSum = INT_MIN + 30000;
    int maxSum = INT_MIN;
    for(auto n : nums) {
      currentMinSum = min(n, currentMinSum + n);
      minSum = min(minSum, currentMinSum);
      currentMaxSum = max(n, currentMaxSum + n);
      maxSum = max(maxSum, currentMaxSum);
    }
    return maxSum > 0 ? max(accumulate(nums.begin(), nums.end(), 0) - minSum, maxSum) : maxSum;
  }
};

// Accepted
// 111/111 cases passed (49 ms)
// Your runtime beats 98.93 % of cpp submissions
// Your memory usage beats 20.64 % of cpp submissions (40.2 MB)
// @lc code=end

