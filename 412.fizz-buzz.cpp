/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
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
  vector<string> fizzBuzz(int n) {
    vector<string> answer;
    answer.reserve(n);
    for(int i = 1; i <= n; ++i) {
      if (i % 15 == 0) {
        answer.emplace_back("FizzBuzz");
      } else if (i % 3 == 0) {
        answer.emplace_back("Fizz");
      } else if (i % 5 == 0) {
        answer.emplace_back("Buzz");
      } else {
        answer.emplace_back(to_string(i));
      }
    }
    return answer;
  }
};

// Accepted
// 8/8 cases passed (4 ms)
// Your runtime beats 70.49 % of cpp submissions
// Your memory usage beats 78.11 % of cpp submissions (7.4 MB)
// @lc code=end
