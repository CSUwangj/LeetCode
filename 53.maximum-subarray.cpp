/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
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
  int maxSubArray(vector<int>& nums) {
    int answer = INT_MIN;
    int sum = 0;
    for(auto i : nums) {
      sum += i;
      if(answer < sum) {
        answer = sum;
      }
      if(sum < 0) {
        sum = 0;
      }
    }
    return answer;
  }
};

// Accepted
// 209/209 cases passed (109 ms)
// Your runtime beats 43.26 % of cpp submissions
// Your memory usage beats 53.84 % of cpp submissions (67.7 MB)
// @lc code=end
