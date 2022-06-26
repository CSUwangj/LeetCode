/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int len = nums.size();
    int sum = (len + 1) * len / 2;
    for(auto i : nums) sum -= i;
    return sum;
  }
};

// Accepted
// 122/122 cases passed (11 ms)
// Your runtime beats 99.14 % of cpp submissions
// Your memory usage beats 93.84 % of cpp submissions (17.9 MB)
// @lc code=end

