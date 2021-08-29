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
    int len = nums.size();
    long long all = 1;
    int count = 0;
    int pos = 0;
    if(nums.front() != 1) {
      count += 1;
    } else {
      pos += 1;
    }
    while(pos < len && all < n) {
      while(all < n && all < nums[pos] - 1) {
        all = all + all + 1;
        count += 1;
      }
      all += nums[pos];
      pos += 1;
    }
    while(all < n) {
      all = all + all + 1;
      count += 1;
    }
    return count;
  }
};

// Accepted
// 146/146 cases passed (4 ms)
// Your runtime beats 94.37 % of cpp submissions
// Your memory usage beats 48.45 % of cpp submissions (11.4 MB)
// @lc code=end

