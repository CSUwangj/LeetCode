/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
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
  string addStrings(string num1, string num2) {
    string answer;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int len1 = num1.length();
    int len2 = num2.length();
    int carry = 0;
    int pos;
    for(pos = 0; pos < len1 && pos < len2; ++pos) {
      int result = num1[pos] + num2[pos] - '0' * 2 + carry;
      answer.push_back(result % 10 + '0');
      carry = result / 10;
    }
    for(; pos < len1; ++pos) {
      int result = num1[pos] + carry - '0';
      answer.push_back(result % 10 + '0');
      carry = result / 10;
    }
    for(; pos < len2; ++pos) {
      int result = num2[pos] + carry - '0';
      answer.push_back(result % 10 + '0');
      carry = result / 10;
    }
    if(carry) answer.push_back('1');
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 317/317 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 45.44 % of cpp submissions (6.8 MB)
// @lc code=end

