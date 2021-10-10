/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
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
  bool canJump(vector<int>& nums) {
    int cur = 0;
    int len = nums.size();
    for(int i = 0; i < len && i <= cur; ++i) {
      cur = max(cur, i + nums[i]);
      if(cur >= len - 1) return true;
    }
    return false;
  }
};

// Accepted
// 166/166 cases passed (32 ms)
// Your runtime beats 99.93 % of cpp submissions
// Your memory usage beats 49.19 % of cpp submissions (48.3 MB)
// @lc code=end

