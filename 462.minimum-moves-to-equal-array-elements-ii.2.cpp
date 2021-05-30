/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
class Solution {
public:
  int minMoves2(vector<int>& nums) {
    int answer = 0;
    sort(nums.begin(), nums.end());
    int target = nums[nums.size() / 2];
    for(auto i : nums) answer += abs(i - target);
    return answer;
  }
};
// @lc code=end

