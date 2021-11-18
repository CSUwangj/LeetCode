/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    vector<int> dp(len, 1);
    vector<int> child(len, -1);
    
    for(int i = 1; i < len; ++i) {
      for(int j = 0; j < i; ++j) {
        if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          child[i] = j;
        }
      }
    }
    
    int answerLen = 0;
    int answerEnd = -1;
    for(int i = 0; i < len; ++i) {
      if(dp[i] > answerLen) {
        answerLen = dp[i];
        answerEnd = i;
      }
    }
    
    vector<int> answer;
    while(answerEnd != -1) {
      answer.push_back(nums[answerEnd]);
      answerEnd = child[answerEnd];
    }
    
    return answer;
  }
};

// Accepted
// 48/48 cases passed (32 ms)
// Your runtime beats 97.22 % of cpp submissions
// Your memory usage beats 35.59 % of cpp submissions (8.8 MB)
// @lc code=end

