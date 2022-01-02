/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
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
  int smallestRepunitDivByK(int k) {
    if(!(k & 1)) return -1;
    int cur = 0;
    int answer = 0;
    set<int> visit;
    do {
      visit.insert(cur);
      cur *= 10;
      cur += 1;
      cur %= k;
      answer += 1;
    } while(cur && !visit.count(cur));
    return cur ? -1 : answer;
  }
};

// Accepted
// 70/70 cases passed (76 ms)
// Your runtime beats 5.04 % of cpp submissions
// Your memory usage beats 9.24 % of cpp submissions (14.5 MB)
// @lc code=end
