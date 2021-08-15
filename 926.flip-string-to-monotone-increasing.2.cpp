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
    int ones = 0, answer = 0;
    int len = s.length();
    for(int i = 0; i < len; i++){
      ones += (s[i] == '1');
      answer = min(ones, answer + (s[i] == '0'));
    }
    return answer;
  }
};

// Accepted
// 93/93 cases passed (8 ms)
// Your runtime beats 53.5 % of cpp submissions
// Your memory usage beats 18.5 % of cpp submissions (11.2 MB)
// @lc code=end

