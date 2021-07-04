/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
public:
  string removeDuplicates(string s) {
    string answer;
    for(auto c : s) {
      if(answer.length() && answer.back() == c) {
        answer.pop_back();
      } else {
        answer.push_back(c);
      }
    }
    return answer;
  }
};
// @lc code=end

