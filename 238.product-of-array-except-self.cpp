/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
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
  vector<int> productExceptSelf(vector<int>& nums) {
    int sum = nums[0];
    int n = nums.size();
    vector<int> ans(n);
    ans[0] = 1;

    for(int i = 1; i < n; ++i){
      ans[i] = sum;
      sum = sum * nums[i];
    }

    sum = 1;

    for(int i = n - 1; i >= 0; --i){
      ans[i] = ans[i] * sum;
      sum = sum * nums[i];
    }

    return ans;
  }
};

// Accepted
// 20/20 cases passed (8 ms)
// Your runtime beats 99.98 % of cpp submissions
// Your memory usage beats 56.08 % of cpp submissions (24.1 MB)
// @lc code=end

