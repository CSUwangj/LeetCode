/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
class Solution {
public:
  string reverseOnlyLetters(string s) {
    int begin = 0;
    int end = s.length() - 1;
    while(begin < end) {
      while(begin < end && !isalpha(s[begin])) begin += 1;
      while(begin < end && !isalpha(s[end])) end -= 1;
      if(begin < end) swap(s[begin], s[end]);
      begin += 1;
      end -= 1;
    }
    return s;
  }
};

// Accepted
// 115/115 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 65.04 % of cpp submissions (6 MB)
// @lc code=end

