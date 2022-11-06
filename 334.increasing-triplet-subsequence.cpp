/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int min = INT_MAX, middle = INT_MAX;
    for(auto i : nums) {
      if(i < min) {
        min = i;
      } else if (i > min && i < middle) {
        middle = i;
      } else if (i > middle) {
        return true;
      }
    }
    return false;
  }
};

// Accepted
// 76/76 cases passed (79 ms)
// Your runtime beats 88.38 % of cpp submissions
// Your memory usage beats 67.34 % of cpp submissions (61.6 MB)
// @lc code=end

