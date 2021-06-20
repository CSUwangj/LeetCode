/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */

// @lc code=start
const int MOD = 1e9 + 7;
const int SZ = 1000;
template<int N>
struct Table{
  constexpr Table() : values() {
    if(N < 1) return;
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
  int values[N + 1][SZ + 1] = {};
};
constexpr auto table = Table<333>();
int values[2][SZ + 1] = {};

void compute(int n) {
  for(int i = 0; i <= SZ; ++i) values[1][i] = table.values[333][i];
  for(int i = 334; i <= n; ++i) {
    int parity = i & 1;
    int J = i * (i - 1) / 2;
    J = J > SZ ? SZ : J;
    for(int j = 0; j <= J; ++j) {
      values[parity][j] = (j ? values[parity][j - 1] : 0) + values[!parity][j] - (i > j ? 0 : values[!parity][j - i]);
      values[parity][j] = (values[parity][j] % MOD + MOD) % MOD;
    }
    for(int j = J + 1; j <= SZ; ++j) {
      values[parity][j] = values[parity][j - 1];
    }
  }
}


class Solution {
public:
  int kInversePairs(int n, int k) {
    if(!k) return 1;
    if(k == 1) return n - 1;
    int answer;
    if(n <= 333) {
      answer = table.values[n][k] - table.values[n][k - 1];
      answer = (answer % MOD + MOD) % MOD;
    } else {
      compute(n);
      int parity = n & 1;
      answer = values[parity][k] - values[parity][k - 1];
      answer = (answer % MOD + MOD) % MOD;
    }
    return answer;
  }
};
// @lc code=end

