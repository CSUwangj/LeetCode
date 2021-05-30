/*
 * @lc app=leetcode id=1223 lang=cpp
 *
 * [1223] Dice Roll Simulation
 */

// @lc code=start
const int MOD = 1e9 + 7;
class Solution {
  int dp[6][16][5000] = {};
public:
  int dieSimulator(int n, vector<int>& rollMax) {
    for(int i = 0; i < 6; ++i) {
      dp[i][0][0] = 1;
      dp[i][1][0] = 1;
    }
    for(int len = 1; len < n; ++len) {
      for(int dice = 0; dice < 6; ++dice) {
        for(int prevDice = 0; prevDice < 6; ++prevDice) {
          if(dice == prevDice) continue;
          dp[dice][1][len] += dp[prevDice][0][len - 1];
          dp[dice][1][len] %= MOD;
        }
        dp[dice][0][len] = dp[dice][1][len];
        for(int i = 1; i < rollMax[dice] && dp[dice][i][len - 1]; ++i) {
          dp[dice][i + 1][len] = dp[dice][i][len - 1];
          dp[dice][0][len] += dp[dice][i][len - 1];
          dp[dice][0][len] %= MOD;
        }
      }
    }
    int answer = 0;
    for(int i = 0; i < 6; ++i) {
      answer += dp[i][0][n - 1];
      answer %= MOD;
    }
    return answer;
  }
};
// @lc code=end

