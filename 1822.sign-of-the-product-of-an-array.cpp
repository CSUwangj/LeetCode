/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
template <typename T> int sgn(T val) {
  return (T(0) < val) - (val < T(0));
}
class Solution {
public:
  int arraySign(vector<int>& nums) {
    int answer = 1;
    for(auto n : nums) {
      answer *= sgn(n);
    }

    return answer;
  }
};

// Accepted
// 76/76 cases passed (8 ms)
// Your runtime beats 27.4 % of cpp submissions
// Your memory usage beats 86.28 % of cpp submissions (10.1 MB)
// @lc code=end

