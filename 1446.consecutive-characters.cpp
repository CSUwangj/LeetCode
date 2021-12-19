/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
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
  int maxPower(string s) {
    int answer = 0;
    int cur = 0;
    char last = 0;
    for(auto c : s) {
      if(c != last) {
        last = c;
        cur = 0;
      }
      cur += 1;
      answer = max(answer, cur);
    }
    return answer;
  }
};

// Accepted
// 333/333 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 72.13 % of cpp submissions (6.8 MB)
// @lc code=end
