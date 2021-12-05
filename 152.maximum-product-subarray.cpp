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
    int answer = *max_element(nums.begin(), nums.end());
    int product = 1;
    int maxNegative = INT_MIN;
    int minPositive = 1;
    bool first = true;
    for(auto num : nums) {
      if(!num) {
        product = 1;
        maxNegative = INT_MIN;
        minPositive = 1;
        first = true;
      } else {
        product *= num;
        if(product < 0) {
          maxNegative = max(maxNegative, product);
          if(first) {
            answer = max(answer, product);
          } else {
            answer = max(answer, product / maxNegative);
          }
          first = false;
        } else {
          minPositive = min(minPositive, product);
          answer = max(answer, product / minPositive);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 187/187 cases passed (4 ms)
// Your runtime beats 81.49 % of cpp submissions
// Your memory usage beats 12.82 % of cpp submissions (11.9 MB)
// @lc code=end
