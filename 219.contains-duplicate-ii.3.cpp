/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
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
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int len = nums.size();
    unordered_set<int> st;
    for(int i = 0; i < k && i < len; ++i) {
      auto [_, insert] = st.insert(nums[i]);
      if(!insert) return true;
    }
    for(int i = k; i < len; ++i) {
      auto [_, insert] = st.insert(nums[i]);
      if(!insert) return true;
      st.erase(nums[i - k]);
    }
    return false;
  }
};

// Accepted
// 51/51 cases passed (124 ms)
// Your runtime beats 99.84 % of cpp submissions
// Your memory usage beats 84.48 % of cpp submissions (72.3 MB)
// @lc code=end
