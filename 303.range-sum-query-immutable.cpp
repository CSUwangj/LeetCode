/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class NumArray {
  vector<int> prefix{0};
public:
  NumArray(vector<int>& nums) {
    for(int i = 0; i < nums.size(); ++i) {
      prefix.push_back(prefix[i] + nums[i]);
    }
  }
  
  int sumRange(int left, int right) {
    return prefix[right + 1] - prefix[left];
  }
};

// Accepted
// 15/15 cases passed (20 ms)
// Your runtime beats 87.17 % of cpp submissions
// Your memory usage beats 11.03 % of cpp submissions (17.3 MB)
// @lc code=end

