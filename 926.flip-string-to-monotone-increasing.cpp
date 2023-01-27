/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
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
  int minFlipsMonoIncr(string s) {
    int ones = 0;
    int len = s.length();
    for(auto c : s) {
      ones += (c & 1);
    }
    int zeros = len - ones;
    int currentOnes = 0;
    int currentZeros = 0;
    int answer = zeros;
    for(auto c : s) {
      currentZeros += !(c & 1);
      currentOnes += (c & 1);
      answer = min(answer, currentOnes + zeros - currentZeros);
    }
    return answer;
  }
};

// Accepted
// 93/93 cases passed (9 ms)
// Your runtime beats 99.49 % of cpp submissions
// Your memory usage beats 52.66 % of cpp submissions (11.2 MB)
// @lc code=end

