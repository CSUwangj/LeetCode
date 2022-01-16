/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
  string addBinary(string a, string b) {
    int len1 = a.length();
    int len2 = b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int pos = 0;
    int carry = 0;
    string answer;
    for(; pos < len1 && pos < len2; ++pos) {
      int result = a[pos] + b[pos] + carry;
      answer.push_back('0' + (result & 1));
      carry = ((result >> 1) & 1);
    }
    int len = len1;
    string *target = &a;
    if(len1 < len2) {
      len = len2;
      target = &b;
    }
    while(carry && pos < len) {
      if((*target)[pos++] == '1') {
        answer.push_back('0');
      } else {
        answer.push_back('1');
        carry = 0;
      }
    }
    while(pos < len) {
      answer.push_back((*target)[pos++]);
    }
    if(carry) {
      answer.push_back('1');
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// Accepted
// 294/294 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 96.62 % of cpp submissions (6.1 MB)
// @lc code=end
