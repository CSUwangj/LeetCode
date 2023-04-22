/*
 * @lc app=leetcode id=2348 lang=cpp
 *
 * [2348] Number of Zero-Filled Subarrays
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
  long long zeroFilledSubarray(vector<int>& nums) {
    int count = 0;
    long long answer = 0;
    for(auto i : nums) {
      count += !i;
      if(i && count) {
        answer += 1LL * count * (count + 1) / 2;
        count = 0;
      }
    }
    answer += 1LL * count * (count + 1) / 2;
    return answer;
  }
};

// Accepted
// 48/48 cases passed (134 ms)
// Your runtime beats 98.49 % of cpp submissions
// Your memory usage beats 99.55 % of cpp submissions (106.4 MB)
// @lc code=end

