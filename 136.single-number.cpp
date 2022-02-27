/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
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
  int singleNumber(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, [](int a, int b) {
      return a ^ b;
    });
  }
};

// Accepted
// 61/61 cases passed (27 ms)
// Your runtime beats 53.51 % of cpp submissions
// Your memory usage beats 50.83 % of cpp submissions (17 MB)
// @lc code=end
