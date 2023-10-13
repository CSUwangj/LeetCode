/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start
class Solution {
public:
  int numIdenticalPairs(vector<int>& nums) {
    vector<int> count(101);
    int answer = 0;
    for(auto n : nums) {
      answer += count[n];
      count[n] += 1;
    }
    return answer;
  }
};

// Accepted
// 48/48 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 7.1 % of cpp submissions (7.9 MB)
// @lc code=end

