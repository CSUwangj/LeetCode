/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
public:
  int subarraysDivByK(vector<int>& nums, int k) {
    int cnt[k];
    memset(cnt, 0, sizeof(cnt));
    int sum = 0;
    int answer = 0;
    cnt[0] = 1;
    for(auto i : nums) {
      sum = ((sum + i) % k + k) % k;
      answer += cnt[sum];
      cnt[sum] += 1;
    }
    return answer;
  }
};

// Accepted
// 73/73 cases passed (40 ms)
// Your runtime beats 97.32 % of cpp submissions
// Your memory usage beats 98.91 % of cpp submissions (29.6 MB)
// @lc code=end

