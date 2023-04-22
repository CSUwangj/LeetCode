/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

// @lc code=start
class Solution {
  int dp[10][50][50];
  int prefixSum[51][51] = {};
  int rows;
  int cols;
  const int MOD = 1e9 + 7;
public:
  int ways(vector<string>& pizza, int k) {
    rows = pizza.size();
    cols = pizza.front().size();
    memset(dp, -1, k * sizeof(dp[0]));
    for(int row = rows - 1; row >= 0; --row) {
      for(int col = cols - 1; col >= 0; --col) {
        prefixSum[row][col] = prefixSum[row][col + 1] + prefixSum[row + 1][col] - prefixSum[row + 1][col + 1] + (pizza[row][col] == 'A');
      }
    }

    return solve(k - 1, 0, 0);
  }

  int solve(int k, int row, int col) {
    if(!prefixSum[row][col]) return 0;
    if(k == 0) return 1;
    if(dp[k][row][col] != -1) return dp[k][row][col];
    int result = 0;
    for(int newRow = row + 1; newRow < rows; ++newRow) {
      if(prefixSum[row][col] - prefixSum[newRow][col] > 0){
        result += solve(k - 1, newRow, col);
        result %= MOD;
      }
    }
    for(int newCol = col + 1; newCol < cols; ++newCol) {
      if(prefixSum[row][col] - prefixSum[row][newCol] > 0) {
        result += solve(k - 1, row, newCol);
        result %= MOD;
      }
    }
    dp[k][row][col] = result;
    return result;
  }
};

// Accepted
// 53/53 cases passed (7 ms)
// Your runtime beats 98.95 % of cpp submissions
// Your memory usage beats 94.5 % of cpp submissions (7.6 MB)
// @lc code=end

