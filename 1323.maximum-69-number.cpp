/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

// @lc code=start
class Solution {
public:
  int maximum69Number (int num) {
    auto s = to_string(num);
    for(auto &c : s) {
      if(c == '6') {
        c = '9';
        break;
      }
    }
    return stoi(s);
  }
};

// Accepted
// 153/153 cases passed (7 ms)
// Your runtime beats 9.01 % of cpp submissions
// Your memory usage beats 45.85 % of cpp submissions (6 MB)
// @lc code=end

