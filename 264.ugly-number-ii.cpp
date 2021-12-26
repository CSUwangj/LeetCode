/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
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
  int nthUglyNumber(int n) {
    int dp[n];
    dp[0] = 1;
    int two = 0, three = 0, five = 0;
    int cnt = 1;
    while(cnt < n) {
      int new_two = dp[two]*2;
      int new_three = dp[three]*3;
      int new_five = dp[five]*5;
      int new_num = min({new_two, new_three, new_five});
      if(new_two == new_num) two += 1;
      if(new_three == new_num) three += 1;
      if(new_five == new_num) five += 1;
      dp[cnt++] = new_num;
    }
    return dp[n - 1];
  }
};

// Accepted
// 596/596 cases passed (4 ms)
// Your runtime beats 93.41 % of cpp submissions
// Your memory usage beats 88.63 % of cpp submissions (5.9 MB)
// @lc code=end

