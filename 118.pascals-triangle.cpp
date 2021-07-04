/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> answer(numRows);
    answer[0] = {1};
    for(int i = 1; i < numRows; ++i) {
      for(int j = 0; j <= i; ++j) {
        if(!j || j == i) {
          answer[i].push_back(1);
        } else {
          answer[i].push_back(answer[i - 1][j - 1] + answer[i - 1][j]);
        }
      }
    }
    return answer;
  }
};
// @lc code=end

