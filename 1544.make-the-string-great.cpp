/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution {
public:
  string makeGood(string s) {
    string answer;
    for(auto c : s) {
      if(answer.length() && answer.back() != c && (answer.back() == tolower(c) || answer.back() == toupper(c))) {
        answer.pop_back();
      } else {
        answer.push_back(c);
      }
    }
    return answer;
  }
};

// Accepted
// 334/334 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 97.69 % of cpp submissions (6.1 MB)
// @lc code=end

