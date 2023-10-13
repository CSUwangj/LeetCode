/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
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
  int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    int start = 0;
    int answer = INT_MAX;
    for(int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      while(sum >= target) {
        answer = min(answer, i - start + 1);
        sum -= nums[start];
        start += 1;
      }
    }
    return answer == INT_MAX ? 0 : answer;
  }
};

// Accepted
// 20/20 cases passed (28 ms)
// Your runtime beats 99.24 % of cpp submissions
// Your memory usage beats 71.68 % of cpp submissions (28.1 MB)
// @lc code=end

