/*
 * @lc app=leetcode id=1641 lang=cpp
 *
 * [1641] Count Sorted Vowel Strings
 */

// @lc code=start
class Solution {
public:
  int countVowelStrings(int n) {
    int dp[5] = {1, 1, 1, 1, 1};
    for(int i = 1; i < n; ++i) {
      for(int j = 1; j < 5; ++j) dp[j] += dp[j-1];
    }
    int answer = 0;
    for(int i = 0; i < 5; ++i) answer += dp[i];
    return answer;
  }
};

// Accepted
// 41/41 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 85.48 % of cpp submissions (5.8 MB)
// @lc code=end

