/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
  void generateParenthesis(
    vector<string> &result,
    string &cur,
    int rest,
    int left
  ) {
    if(!rest && !left) {
      result.push_back(cur);
      return;
    }
    if(rest) {
      cur.push_back('(');
      generateParenthesis(result, cur, rest - 1, left + 1);
      cur.pop_back();
    }
    if(left) {
      cur.push_back(')');
      generateParenthesis(result, cur, rest, left - 1);
      cur.pop_back();
    }
  }
public:
  vector<string> generateParenthesis(int n) {
    vector<string> answer;
    string tmp;
    generateParenthesis(answer, tmp, n, 0);
    return answer;
  }
};
// @lc code=end

