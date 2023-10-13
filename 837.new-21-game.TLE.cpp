/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

// @lc code=start
class Solution {
public:
  double new21Game(int n, int k, int maxPts) {
    if(k == 0) return 1;
    int maxP = k + maxPts;
    if(n + 1 >= maxP) return 1;
    vector<double> probability(maxP);
    probability[0] = 1;

    for(int i = 1; i < maxP; ++i) {
      for(int j = 1; j <= maxPts && i - j >= 0; ++j) {
        if(i - j >= k) continue;
        probability[i] += probability[i - j] / maxPts;
      }
    }

    double answer = 0;
    for(int i = k; i <= n; ++i) {
      answer += probability[i];
    }

    return answer;
  }
};
// @lc code=end

