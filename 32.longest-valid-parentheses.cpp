/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
template<typename T>
class reversion_wrapper {
private:
  T& iterable;
public:
  explicit reversion_wrapper(T& iterable): iterable{iterable} {}
  auto begin() const { return std::rbegin(iterable); }
  auto end() const { return std::rend(iterable); }
};

class Solution {
public:
  int longestValidParentheses(string s) {
    int left = 0;
    int right = 0;
    int answer = 0;
    for(auto c : s) {
      if(c == '(') {
        left += 1;
      } else {
        right += 1;
        if(left == right) {
          answer = max(answer, left << 1);
        } else if (left < right) {
          left = 0;
          right = 0;
        }
      }
    }
    left = 0;
    right = 0;
    for(auto c : reversion_wrapper(s)) {
      if(c == ')') {
        right += 1;
      } else {
        left += 1;
        if(left == right) {
          answer = max(answer, left << 1);
        } else if(left > right) {
          left = 0;
          right = 0;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 231/231 cases passed (4 ms)
// Your runtime beats 73.76 % of cpp submissions
// Your memory usage beats 96.04 % of cpp submissions (6.7 MB)
// @lc code=end

