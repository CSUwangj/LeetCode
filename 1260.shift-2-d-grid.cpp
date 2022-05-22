/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
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
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid.front().size();
    k %= (rows * cols);
    if(!k) return move(grid);
    vector<int> temp;
    temp.reserve(k);
    for(int row = 0; temp.size() != k && row < rows; ++row) {
      for(int col = 0; temp.size() != k && col < cols; ++col) {
        temp.push_back(grid[row][col]);
      }
    }
    for(int row = rows - 1; row >= 0; --row) {
      for(int col = cols - 1; row * cols + col >= k && col >= 0; --col) {
        cout << row << ' '<< col << endl;
        int targetPos = (row * cols + col + k) % (rows * cols);
        grid[targetPos / cols][targetPos % cols] = grid[row][col];
      }
    }
    for(int i = 0; i < k; ++i) {
      int targetPos = (i + k) % (rows * cols);
      grid[targetPos / cols][targetPos % cols] = temp[i];
    }
    return move(grid);
  }
};

// Accepted
// 107/107 cases passed (46 ms)
// Your runtime beats 47.01 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (13.6 MB)
// @lc code=end
