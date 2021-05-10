/*
 * @lc app=leetcode id=1400 lang=cpp
 *
 * [1400] Construct K Palindrome Strings
 */

// @lc code=start
class Solution {
public:
  bool canConstruct(string s, int k) {
    int cnt[26] = {};
    for(auto c : s) cnt[c - 'a'] += 1;
    int mmin = 0;
    for(int i = 0; i < 26; ++i) mmin += cnt[i] & 1;
    mmin = max(mmin, 1);
    return k >= mmin && k <= s.length();
  }
};
// @lc code=end

