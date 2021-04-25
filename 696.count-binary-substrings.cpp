/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
  int countBinarySubstrings(string s) {
    int prev = 0;
    int cur = 0;
    int answer = 0;
    char curChar = '#';
    for(auto c : s) {
      if(c != curChar) {
        answer += min(prev, cur);
        prev = cur;
        cur = 0;
        curChar = c;
      }
      cur += 1;
    }
    answer += min(prev, cur);
    return answer;
  }
};
// Accepted
// 90/90 cases passed (12 ms)
// Your runtime beats 99.74 % of cpp submissions
// Your memory usage beats 91.29 % of cpp submissions (10.3 MB)
// @lc code=end

