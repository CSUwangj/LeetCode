/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
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
  int lengthOfLastWord(string s) {
    auto b = s.rbegin();
    while(b != s.rend() && isspace(*b)) ++b;
    int answer = 0;
    while(b != s.rend() && !isspace(*b)) {
      answer += 1;
      ++b;
    }
    return answer;
  }
};

// Accepted
// 58/58 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 52.2 % of cpp submissions (6.6 MB)
// @lc code=end
