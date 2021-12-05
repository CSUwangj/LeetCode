/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
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
  int maxProduct(vector<int>& nums) {
    int answer = INT_MIN;
    int l = 1;
    int r = 1;
    int len = nums.size();
    for(int i = 0; i < len; ++i) {
      l *= nums[i];
      r *= nums[len - i - 1];
      answer = max({l, r, answer});
      if(!l) l = 1;
      if(!r) r = 1;
    }
    return answer;
  }
};

// Accepted
// 187/187 cases passed (4 ms)
// Your runtime beats 81.49 % of cpp submissions
// Your memory usage beats 52.62 % of cpp submissions (11.7 MB)
// @lc code=end
