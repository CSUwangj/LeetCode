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
// 170/170 cases passed (56 ms)
// Your runtime beats 98.71 % of cpp submissions
// Your memory usage beats 79.88 % of cpp submissions (48.3 MB)
// @lc code=end

