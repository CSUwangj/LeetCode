/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
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
  double new21Game(int n, int k, int maxPts) {
    if(k == 0) return 1;
    int maxP = k + maxPts;
    if(n + 1 >= maxP) return 1;
    vector<double> probability(maxP);
    probability[0] = 1;

    double sum = 1;
    double answer = 0;
    for(int i = 1; i <= n; ++i) {
      probability[i] = sum / maxPts;
      
      if(i < k) {
        sum += probability[i];
      } else {
        answer += probability[i];
      }

      if(i >= maxPts) sum -= probability[i - maxPts]; 
    }

    return answer;
  }
};

// Accepted
// 151/151 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 20.16 % of cpp submissions (10.7 MB)
// @lc code=end

