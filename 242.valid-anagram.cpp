/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
  bool isAnagram(string s, string t) {
    vector<int> sc(26);
    vector<int> tc(26);
    for(auto c : s) sc[c - 'a'] += 1;
    for(auto c : t) tc[c - 'a'] += 1;
    return sc == tc;
  }
};

// Accepted
// 36/36 cases passed (5 ms)
// Your runtime beats 92.06 % of cpp submissions
// Your memory usage beats 7.79 % of cpp submissions (7.4 MB)
// @lc code=end

