/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
class Solution {
public:
  string removeStars(string s) {
    string answer;
    for(auto c : s) {
      if(c == '*') {
        answer.pop_back();
      } else {
        answer.push_back(c);
      }
    }

    return answer;
  }
};

// Accepted
// 65/65 cases passed (67 ms)
// Your runtime beats 96.67 % of cpp submissions
// Your memory usage beats 86.36 % of cpp submissions (25.7 MB)
// @lc code=end

