/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  string removeOne(const string &s, char front, char back) {
    string result;
    int count = 0;
    for(auto c : s) {
      if(c == front) {
        count += 1;
        result.push_back(front);
      } else if(c == back) {
        if(!count) continue;
        count -= 1;
        result.push_back(back);
      } else {
        result.push_back(c);
      }
    }
    return result;
  }
public:
  string minRemoveToMakeValid(string s) {
    int count = 0;
    string answer = removeOne(s, '(', ')');
    reverse(answer.begin(), answer.end());
    answer = removeOne(answer, ')', '(');
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 62/62 cases passed (24 ms)
// Your runtime beats 78.01 % of cpp submissions
// Your memory usage beats 21.74 % of cpp submissions (12.3 MB)
// @lc code=end
