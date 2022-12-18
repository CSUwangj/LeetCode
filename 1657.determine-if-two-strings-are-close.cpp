/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if(word1.length() != word2.length()) return false;
    int cnt1[26] = {0};
    int cnt2[26] = {0};
    for(auto c : word1) cnt1[c-'a'] += 1;
    for(auto c : word2) cnt2[c-'a'] += 1;
    for(int i = 0; i < 26; ++i) {
      if((cnt1[i] && !cnt2[i]) || (!cnt1[i] && cnt2[i])) return false;
    }
    sort(cnt1, cnt1+26);
    sort(cnt2, cnt2+26);
    for(int i = 0; i < 26; ++i) {
      if(cnt1[i] != cnt2[i]) return false;
    }
    return true;
  }
};

// Accepted
// 152/152 cases passed (160 ms)
// Your runtime beats 72.75 % of cpp submissions
// Your memory usage beats 82.93 % of cpp submissions (20.4 MB)
// @lc code=end

