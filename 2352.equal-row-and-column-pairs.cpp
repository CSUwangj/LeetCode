/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */

// @lc code=start
class Solution {
public:
  int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    int answer = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        bool valid = true;
        for(int k = 0; k < n && valid; ++k) {
          if(grid[i][k] != grid[k][j]) valid = false;
        }
        answer += valid;
      }
    }

    return answer;
  }
};

// Accepted
// 72/72 cases passed (574 ms)
// Your runtime beats 8.87 % of cpp submissions
// Your memory usage beats 86.2 % of cpp submissions (23.4 MB)
// @lc code=end

