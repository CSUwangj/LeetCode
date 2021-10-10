/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.front().size();

    int answer = 0;

    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(j != cols - 1 && grid[i][j] != grid[i][j + 1]) {
          answer += 1;
        }
        if(i != rows - 1 && grid[i][j] != grid[i + 1][j]) {
          answer += 1;
        }
      }
    }
    for(int i = 0; i < rows; ++i) {
      answer += grid[i][0];
      answer += grid[i][cols - 1];
    }
    for(int i = 0; i < cols; ++i) {
      answer += grid[0][i];
      answer += grid[rows - 1][i];
    }

    return answer;
  }
};

// Accepted
// 5833/5833 cases passed (119 ms)
// Your runtime beats 38.48 % of cpp submissions
// Your memory usage beats 58.06 % of cpp submissions (96.2 MB)
// @lc code=end

