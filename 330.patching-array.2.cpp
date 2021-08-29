/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
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
  int minPatches(vector<int>& nums, int n) {
    int count = 0;
    int pos = 0;
    int len = nums.size();
    long long next = 1;
    while(next <= n) {
      if(pos < len && nums[pos] <= next) {
        next += nums[pos];
        pos += 1;
      } else {
        next += next;
        count += 1;
      }
    }
    return count;
  }
};

// Accepted
// 146/146 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 48.45 % of cpp submissions (11.5 MB)
// @lc code=end

