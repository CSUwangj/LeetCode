/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
  int titleToNumber(string columnTitle) {
    int answer = 0;
    for(auto c : columnTitle) {
      answer *= 26;
      answer += c - 'A' + 1;
    }
    return answer;
  }
};

// Accepted
// 1002/1002 cases passed (4 ms)
// Your runtime beats 47.34 % of cpp submissions
// Your memory usage beats 67.1 % of cpp submissions (6 MB)
// @lc code=end

