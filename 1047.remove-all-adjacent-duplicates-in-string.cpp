/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
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

// Accepted
// 106/106 cases passed (24 ms)
// Your runtime beats 86.73 % of cpp submissions
// Your memory usage beats 48.01 % of cpp submissions (11 MB)
// @lc code=end

