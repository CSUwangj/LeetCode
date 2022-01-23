/*
 * @lc app=leetcode id=1563 lang=cpp
 *
 * [1563] Stone Game V
 */

// @lc code=start
int dp[501][501];
class Solution {
public:
  int stoneGameV(vector<int>& stone) {
    partial_sum(stone.begin(), stone.end(), stone.begin());
    int len = stone.size();
    memset(dp, 0, sizeof(dp[0]) * (len + 1));
    for(int l = 1; l <= len; ++l) {
      for(int begin = 0; begin + l <= len; ++begin) {
        int sum = stone[l + begin - 1] - (begin ? stone[begin - 1] : 0);
        int prev = begin ? stone[begin - 1] : 0;
        int partition = begin;
        // [begin, partition], (patition, begin + l)
        while((stone[partition] - prev) * 2 < sum) {
          dp[begin][begin + l] = max(dp[begin][begin + l], stone[partition] - prev + dp[begin][partition + 1]);
          partition += 1;
        }
        if((stone[partition] - prev) * 2 == sum) {
          dp[begin][begin + l] = max(dp[begin][begin + l], stone[partition] - prev + dp[begin][partition + 1]);
          dp[begin][begin + l] = max(dp[begin][begin + l], sum + prev - stone[partition] + dp[partition + 1][begin + l]);
          partition += 1;
        }
        while(partition < begin + l) {
          dp[begin][begin + l] = max(dp[begin][begin + l], sum + prev - stone[partition] + dp[partition + 1][begin + l]);
          partition += 1;
        }
      }
    }
    return dp[0][len];
  }
};

// Accepted
// 131/131 cases passed (1758 ms)
// Your runtime beats 5.49 % of cpp submissions
// Your memory usage beats 96.7 % of cpp submissions (10.4 MB)
// @lc code=end
