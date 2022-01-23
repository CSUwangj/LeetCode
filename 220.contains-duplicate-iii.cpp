/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
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
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> st;
    int len = nums.size();
    for(int i = 0; i < k && i < len; ++i) {
      auto it = st.lower_bound(max(1LL * nums[i] - t, 1LL * INT_MIN));
      if(it != st.end() && *it <= 1LL * nums[i] + t) return true;
      st.insert(nums[i]);
    }
    for(int i = k; i < len; ++i) {
      auto it = st.lower_bound(max(1LL * nums[i] - t, 1LL * INT_MIN));
      if(it != st.end() && *it <= 1LL * nums[i] + t) return true;
      st.insert(nums[i]);
      st.erase(nums[i - k]);
    }
    return false;
  }
};

// Accepted
// 53/53 cases passed (71 ms)
// Your runtime beats 18.06 % of cpp submissions
// Your memory usage beats 10.54 % of cpp submissions (18.8 MB)
// @lc code=end

