/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
int answer[10001];
auto _ = [](){
  for(int i = 1; i < 10001; ++i) {
    answer[i] = INT_MAX;
    int bound = sqrt(i);
    for(int j = 1; j <= bound; ++j) {
      answer[i] = min(answer[i], answer[i - j * j] + 1);
    }
  }
  return 0;
}();
class Solution {
public:
  int numSquares(int n) {
    return answer[n];
  }
};

// Accepted
// 588/588 cases passed (2 ms)
// Your runtime beats 96.2 % of cpp submissions
// Your memory usage beats 82.23 % of cpp submissions (6.1 MB)
// @lc code=end

