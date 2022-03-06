/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int last = nums.front();
    int count = 0;
    int diff = 0;
    int answer = 0;
    for(auto n : nums) {
      if(n - last == diff) {
        count += 1;
      } else {
        answer += max(0, count - 2) * (count - 1) / 2;
        count = 2;
        diff = n - last;
      }
      last = n;
    }
    answer += max(0, count - 2) * (count - 1) / 2;
    return answer;
  }
};

// Accepted
// 15/15 cases passed (3 ms)
// Your runtime beats 66.63 % of cpp submissions
// Your memory usage beats 88.02 % of cpp submissions (7.3 MB)
// @lc code=end
