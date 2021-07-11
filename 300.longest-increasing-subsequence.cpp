/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
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
  int lengthOfLIS(vector<int>& nums) {
    vector<int> LIS{nums[0]};
    for(auto i : nums) {
      auto it = lower_bound(LIS.begin(), LIS.end(), i);
      if(it != LIS.end()) {
        *it = i;
      } else {
        LIS.push_back(i);
      }
    }
    return LIS.size();
  }
};
// @lc code=end

