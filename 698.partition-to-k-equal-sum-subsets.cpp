/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  vector<bool> used;
  int left;
  int part;
  int len;
  bool dfs(vector<int>& nums, int rest, int start) {
    if(!left) return true;
    if(rest == 0) return dfs(nums, part, 0);
    for(int i = start; i < len; ++i) {
      if(!used[i] && nums[i] <= rest) {
        used[i] = true;
        left -= 1;
        if(dfs(nums, rest - nums[i], i + 1)) return true;
        used[i] = false;
        left += 1;
      }
    }
    return false;
  }
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    part = accumulate(nums.begin(), nums.end(), 0);
    len = nums.size();
    if(part % k || len < k) return false;
    used.resize(len);
    left = len;
    part /= k;
    for(auto n : nums) {
      if(n > part) return false;
    }
    return dfs(nums, part, 0);
  }
};

// Accepted
// 142/142 cases passed (4 ms)
// Your runtime beats 84.15 % of cpp submissions
// Your memory usage beats 85.03 % of cpp submissions (9 MB)
// @lc code=end

