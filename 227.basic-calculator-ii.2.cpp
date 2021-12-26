/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
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
  int calculate(string s) {
    s.push_back('+');
    char prevSign = '+';
    int prev = 0;
    int cur = 0;
    int result = 0;
    for(auto c : s) {
      if(c == ' ') continue;
      if(isdigit(c)) {
        cur *= 10;
        cur += c - '0';
        continue;
      }
      if(prevSign == '+' || prevSign == '-') {
        result += prev;
        prev = prevSign == '+' ? cur : -cur;
      } else if(prevSign == '*') {
        prev = prev * cur;
      } else {
        prev = prev / cur;
      }
      prevSign = c;
      cur = 0;
    }
    return result + prev;
  }
};

// Accepted
// 109/109 cases passed (4 ms)
// Your runtime beats 98.87 % of cpp submissions
// Your memory usage beats 75.38 % of cpp submissions (7.9 MB)
// @lc code=end

