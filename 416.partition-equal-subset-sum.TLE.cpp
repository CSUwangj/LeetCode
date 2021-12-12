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
    set<int> ways;
    ways.insert(0);
    for(auto i : nums) {
      set<int> newWays;
      for(auto j : ways) {
        newWays.insert(i + j);
      }
      ways.merge(newWays);
    }
    return ways.count(target);
  }
};

// Accepted
// 117/117 cases passed (16 ms)
// Your runtime beats 97.09 % of cpp submissions
// Your memory usage beats 92.1 % of cpp submissions (9.1 MB)
// @lc code=end
