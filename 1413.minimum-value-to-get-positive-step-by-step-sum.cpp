/*
 * @lc app=leetcode id=1413 lang=cpp
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
 */

// @lc code=start
class Solution {
public:
  int minStartValue(vector<int>& nums) {
    int answer = 1;
    int sumRev = 1;
    for(auto i : nums) {
      sumRev -= i;
      if(answer < sumRev) answer = sumRev;
    }
    return answer;
  }
};

// Accepted
// 53/53 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 14.12 % of cpp submissions (7.4 MB)
// @lc code=end

