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
    bitset<10001> dp;
    dp[0] = 1;
    for(auto i : nums) {
      dp |= (dp << i);
    }
    return dp[target];
  }
};

// Accepted
// 117/117 cases passed (4 ms)
// Your runtime beats 99.79 % of cpp submissions
// Your memory usage beats 97.1 % of cpp submissions (9.1 MB)
// @lc code=end
