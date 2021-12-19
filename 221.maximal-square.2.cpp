/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int dp[301][301];
class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();
    int sideLength = 0;
    for(int i = 0; i < rows; ++i) {
      for(int j = 0; j < cols; ++j) {
        if(matrix[i][j] == '1') {
          dp[i + 1][j + 1] = min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
          sideLength = max(sideLength, dp[i + 1][j + 1]);
        } else {
          dp[i + 1][j + 1] = 0;
        }
      }
    }
    return sideLength * sideLength;
  }
};


// Accepted
// 75/75 cases passed (20 ms)
// Your runtime beats 94.4 % of cpp submissions
// Your memory usage beats 75.11 % of cpp submissions (11.4 MB)
// @lc code=end
