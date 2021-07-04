/*
 * @lc app=leetcode id=1269 lang=cpp
 *
 * [1269] Number of Ways to Stay in the Same Place After Some Steps
 */

// @lc code=start
const int MOD = 1e9 + 7;
int ways[2][500];
class Solution {
public:
  int numWays(int steps, int arrLen) {
    if(arrLen == 1) return 1;
    memset(ways, 0, sizeof(ways));
    ways[0][0] = 1;
    int boundary = min(arrLen, 500);
    for(int i = 1; i <= steps; ++i) {
      int parity = i & 1;
      ways[parity][0] = (ways[!parity][0] + ways[!parity][1]) % MOD;
      ways[parity][boundary - 1] = (ways[!parity][boundary - 1] + ways[!parity][boundary - 2]) % MOD;
      for(int j = 1; j < boundary - 1; ++j) {
        ways[parity][j] = ways[!parity][j - 1];
        ways[parity][j] += ways[!parity][j];
        ways[parity][j] %= MOD;
        ways[parity][j] += ways[!parity][j + 1];
        ways[parity][j] %= MOD;
      }
    }
    return ways[steps & 1][0];
  }
};
// @lc code=end

