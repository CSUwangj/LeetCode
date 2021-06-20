/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */

// @lc code=start
const int N = 1001;
const int MOD = 1e9 + 7;

int values[N][N];

struct Solution {
  Solution() {
    if (values[0][0]) return;
    values[0][0] = 1;
    for (int i = 1; i < N; ++i) {
      int sum = 0;
      int end = min(N - 1, i * (i - 1) / 2);
      for (int j = 0; j <= end; ++j) {
        sum += values[i - 1][j];
        if (j >= i) sum -= values[i - 1][j - i];
        if (sum >= MOD) sum -= MOD;
        else if (sum < 0) sum += MOD;
        values[i][j] = sum;
      }
    }
  }

  int kInversePairs(int n, int k) const {
    return values[n][k];
  }
};
// @lc code=end

