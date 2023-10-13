/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    int len = s.length();
    if(len == 1) return false;
    vector<int> factors;
    for(int i = 1; i * i <= len; ++i) {
      if(len % i == 0) {
        factors.push_back(i);
        if(i * i != len && i != 1) factors.push_back(len / i);
      }
    }
    for(auto factor : factors) {
      bool ok = true;
      for(int pos = factor; pos < len && ok; ++pos) {
        if(s[pos % factor] != s[pos]) {
          ok = false;
        }
      }
      if(ok) return true;
    }
    return false;
  }
};

// Accepted
// 129/129 cases passed (18 ms)
// Your runtime beats 67.67 % of cpp submissions
// Your memory usage beats 93.58 % of cpp submissions (9.4 MB)
// @lc code=end

