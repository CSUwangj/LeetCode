/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
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
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0;
    int answer = 0;
    for(auto i : nums) {
      if(!i) {
        count = 0;
      } else {
        count += 1;
      }
      answer = count > answer ? count : answer;
    }
    return answer;
  }
};

// Accepted
// 42/42 cases passed (32 ms)
// Your runtime beats 82.03 % of cpp submissions
// Your memory usage beats 21.16 % of cpp submissions (36.2 MB)
// @lc code=end

