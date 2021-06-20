/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */

// @lc code=start
const int MOD = 1e9 + 7;
int values[1001][1001] = {};
const int SZ = 1000;
void init(int N) {
  values[0][0] = 1;
  for(int i = 1; i <= N; ++i) {
    int nextJ = i * (i + 1) / 2;
    int J = i * (i - 1) / 2;
    J = J > SZ ? SZ : J;
    nextJ = nextJ > SZ ? SZ : nextJ;
    for(int j = 0; j <= J; ++j) {
      values[i][j] = (j ? values[i][j - 1] : 0) + values[i - 1][j] - (i > j ? 0 : values[i - 1][j - i]);
      values[i][j] = (values[i][j] % MOD + MOD) % MOD;
    }
    for(int j = J + 1; j <= nextJ; ++j) {
      values[i][j] = values[i][j - 1];
    }
  }
}

class Solution {
public:
  int kInversePairs(int n, int k) {
    if(!k) return 1;
    init(n);
    int answer = values[n][k] - values[n][k - 1];
    answer = (answer % MOD + MOD) % MOD;
    return answer;
  }
};
// @lc code=end

