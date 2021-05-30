/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
class Solution {
public:
  int minMoves2(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    long long sum = 0;
    for(auto i : nums) sum += i;
    long long cur = 0;
    long long answer = INT_MAX;
    for(long long i = 0; i < len; ++i) {
      answer = min(answer, (nums[i] * i - cur) + (sum - cur - (len - i) * nums[i]));
      cur += nums[i];
    }
    return answer;
  }
};
// @lc code=end

