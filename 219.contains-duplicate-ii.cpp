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

// 52/52 cases passed (200 ms)
// Your runtime beats 89.2 % of cpp submissions
// Your memory usage beats 91.47 % of cpp submissions (72.2 MB)
// @lc code=end
