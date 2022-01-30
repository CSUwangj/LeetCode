/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
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
  void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k %= len;
    if(!k) return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

// Accepted
// 38/38 cases passed (39 ms)
// Your runtime beats 45.28 % of cpp submissions
// Your memory usage beats 52.93 % of cpp submissions (25 MB)
// @lc code=end
