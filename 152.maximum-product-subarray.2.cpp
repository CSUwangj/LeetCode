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
    int product = 1;
    for(auto i : nums) {
      product *= i;
      answer = max(product, answer);
      if(!product) {
        product = 1;
      }
    }

    product = 1;
    for(auto it = nums.rbegin(); it != nums.rend(); ++it) {
      product *= *it;
      answer = max(product, answer);
      if(!product) {
        product = 1;
      }
    }
    return answer;
  }
};

// Accepted
// 187/187 cases passed (4 ms)
// Your runtime beats 81.49 % of cpp submissions
// Your memory usage beats 52.62 % of cpp submissions (11.8 MB)
// @lc code=end
