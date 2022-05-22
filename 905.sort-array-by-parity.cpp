/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
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
  vector<int> sortArrayByParity(vector<int>& nums) {
    int oddPos = 0;
    int evenPos = 0;
    int len = nums.size();
    while(oddPos < len) {
      if(nums[oddPos] % 2 == 0) {
        swap(nums[evenPos], nums[oddPos]);
        evenPos += 1;
      }
      oddPos += 1;
    }
    return move(nums);
  }
};

// Accepted
// 285/285 cases passed (12 ms)
// Your runtime beats 66.01 % of cpp submissions
// Your memory usage beats 95.88 % of cpp submissions (16.1 MB)
// @lc code=end
