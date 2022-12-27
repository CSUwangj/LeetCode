/*
 * @lc app=leetcode id=2389 lang=cpp
 *
 * [2389] Longest Subsequence With Limited Sum
 */

// @lc code=start
class Solution {
public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); ++i) {
      nums[i] += nums[i - 1];
    }
    vector<int> answer;
    answer.reserve(queries.size());
    for(auto query : queries) {
      answer.push_back(upper_bound(nums.begin(), nums.end(), query) - nums.begin());
    }
    return answer;
  }
};

// Accepted
// 39/39 cases passed (22 ms)
// Your runtime beats 87.70 % of cpp submissions
// Your memory usage beats 83.30 % of cpp submissions (13.6 MB)
// @lc code=end

