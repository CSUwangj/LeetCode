/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
  int countNegatives(vector<vector<int>>& grid) {
    int answer = 0;
    for(auto &row : grid) {
      for(auto i : row) {
        answer += i < 0;
      }
    }
    return answer;
  }
};

// Accepted
// 44/44 cases passed (19 ms)
// Your runtime beats 43.59 % of cpp submissions
// Your memory usage beats 71.33 % of cpp submissions (10.4 MB)
// @lc code=end

