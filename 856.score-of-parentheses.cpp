/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

// @lc code=start
class Solution {
public:
  int scoreOfParentheses(string S) {
    int answer = 0;
    int count = 0;
    char last = 0;
    for(auto c : S) {
      if(c == '(') {
        count += 1;
      } else {
        count -= 1;
        if(last == '(') answer += (1 << count);
      }
      last = c;
    }
    return answer;
  }
};

// Accepted
// 86/86 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.93 % of cpp submissions (5.8 MB)
// @lc code=end
