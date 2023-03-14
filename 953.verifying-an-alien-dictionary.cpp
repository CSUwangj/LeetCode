/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class Solution {
public:
  bool isAlienSorted(vector<string>& words, string order) {
    int orderIndex[128] = {};
    int pos = 0;
    for(auto c : order) orderIndex[c] = pos++;
    return is_sorted(words.begin(), words.end(), [&](const string &a, const string &b) {
      for(int i = 0; i < min(a.length(), b.length()); ++i) {
        if(a[i] != b[i]) return orderIndex[a[i]] < orderIndex[b[i]];
      }
      return a.length() < b.length();
    });
  }
};

// Accepted
// 120/120 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.14 % of cpp submissions (9.2 MB)
// @lc code=end

