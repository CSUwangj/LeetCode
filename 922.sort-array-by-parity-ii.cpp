/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
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
  vector<int> sortArrayByParityII(vector<int>& nums) {
    int even = 0;
    int odd = 1;
    int len = nums.size();
    while(even < len) {
      while(even < len && ~nums[even] & 1) even += 2;
      while(odd < len && nums[odd] & 1) odd += 2;
      if(even >= len) break;
      swap(nums[odd], nums[even]);
      odd += 2;
      even += 2;
    }
    return nums;
  }
};

// Accepted
// 61/61 cases passed (12 ms)
// Your runtime beats 97.83 % of cpp submissions
// Your memory usage beats 30.87 % of cpp submissions (21.5 MB)
// @lc code=end

