/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if((sum & 1) || nums.empty()) return false;

    int target = sum >> 1;
    vector<bool> dp(target + 1);
    dp[0] = true;
    for(auto i : nums) {
      for(int j = target; j >= i; --j) {
        if(dp[j - i]) dp[j] = true;
      }
      if(dp[target]) return true;
    }
    return false;
  }
};

// Accepted
// 117/117 cases passed (16 ms)
// Your runtime beats 97.09 % of cpp submissions
// Your memory usage beats 92.1 % of cpp submissions (9.1 MB)
// @lc code=end
