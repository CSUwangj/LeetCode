/*
 * @lc app=leetcode id=1765 lang=cpp
 *
 * [1765] Map of Highest Peak
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
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int rows = isWater.size();
    int cols = isWater.front().size();
    queue<pair<int, int>> q;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(isWater[i][j]) isWater[i][j] = 0;
        else isWater[i][j] = INT_MAX / 2;
      }
    }
    for(int i = 1; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        isWater[i][j] = min(isWater[i - 1][j] + 1, isWater[i][j]);
      }
    }
    for(int i = rows - 2; i >= 0; --i) {
      for(int j = 0; j < cols; ++j) {
        isWater[i][j] = min(isWater[i + 1][j] + 1, isWater[i][j]);
      }
    }
    for(int i = 0; i < rows; ++i) {
      for(int j = 1; j < cols; ++j) {
        isWater[i][j] = min(isWater[i][j - 1] + 1, isWater[i][j]);
      }
      for(int j = cols - 2; j >= 0; --j) {
        isWater[i][j] = min(isWater[i][j + 1] + 1, isWater[i][j]);
      }
    }
    return move(isWater);
  }
};

// Accepted
// 59/59 cases passed (335 ms)
// Your runtime beats 70.03 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (91.7 MB)
// @lc code=end
