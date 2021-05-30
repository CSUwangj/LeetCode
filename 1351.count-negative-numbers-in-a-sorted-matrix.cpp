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
// @lc code=end

