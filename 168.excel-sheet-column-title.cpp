/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
  string convertToTitle(int columnNumber) {
    string answer;
    while(columnNumber) {
      if(columnNumber % 26 != 0) {
        answer.push_back(columnNumber % 26 + 'A' - 1);
      } else {
        answer.push_back('Z');
        columnNumber -= 1;
      }
      columnNumber /= 26;
    }

    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 19/19 cases passed (2 ms)
// Your runtime beats 49.78 % of cpp submissions
// Your memory usage beats 37.93 % of cpp submissions (5.9 MB)
// @lc code=end

