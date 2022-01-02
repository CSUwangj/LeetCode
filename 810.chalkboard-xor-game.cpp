/*
 * @lc app=leetcode id=810 lang=cpp
 *
 * [810] Chalkboard XOR Game
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
  bool xorGame(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0, (int prev, int cur) {
      return prev ^ cur;
    });
    return sum == 0 || nums.size() % 2 == 0;
  }
};

// Accepted
// 168/168 cases passed (17 ms)
// Your runtime beats 6.12 % of cpp submissions
// Your memory usage beats 27.5 % of cpp submissions (13.2 MB)
// @lc code=end
