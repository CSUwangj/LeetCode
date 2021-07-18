/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
  int mp[128] = {};
  int rev[128] = {};
public:
  bool isIsomorphic(string s, string t) {
    int len = s.length();
    for(int i = 0; i < len; ++i) {
      if(mp[s[i]] && mp[s[i]] != t[i]) return false;
      if(rev[t[i]] && rev[t[i]] != s[i]) return false;
      mp[s[i]] = t[i];
      rev[t[i]] = s[i];
    }
    return true;
  }
};
// @lc code=end

