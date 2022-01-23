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
    set<int> st;
    for(int i = 0; i < k && i < len; ++i) {
      if(st.count(nums[i])) return true;
      st.insert(nums[i]);
    }
    for(int i = k; i < len; ++i) {
      if(st.count(nums[i])) return true;
      st.insert(nums[i]);
      st.erase(nums[i - k]);
    }
    return false;
  }
};

// Accepted
// 51/51 cases passed (340 ms)
// Your runtime beats 16.73 % of cpp submissions
// Your memory usage beats 14.53 % of cpp submissions (80.4 MB)
// @lc code=end
