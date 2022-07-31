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

// Accepted
// 30/30 cases passed (16 ms)
// Your runtime beats 55.47 % of cpp submissions
// Your memory usage beats 15.75 % of cpp submissions (10.9 MB)
// @lc code=end

