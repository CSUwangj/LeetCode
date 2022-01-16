/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    size_t len = INT_MAX;
    for(const auto &s : strs) {
      len = min(s.length(), len);
    }
    bool ok = true;
    int subLen = 0;
    while(ok && subLen < len) {
      char c = strs.front()[subLen];
      for(const auto &s : strs) {
        if(s[subLen] != c) {
          ok = false;
          break;
        }
      }
      if(ok) subLen += 1;
    }
    return strs.front().substr(0, subLen);
  }
};

// Accepted
// 123/123 cases passed (12 ms)
// Your runtime beats 10.81 % of cpp submissions
// Your memory usage beats 93.09 % of cpp submissions (9.1 MB)
// @lc code=end
