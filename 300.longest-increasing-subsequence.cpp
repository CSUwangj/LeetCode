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

// Accepted
// 54/54 cases passed (7 ms)
// Your runtime beats 97.92 % of cpp submissions
// Your memory usage beats 69.86 % of cpp submissions (10.5 MB)
// @lc code=end

