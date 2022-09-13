/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int cnt[26] = {};
    for(auto c : magazine) {
      cnt[c - 'a'] += 1;
    }
    for(auto c : ransomNote) {
      cnt[c - 'a'] -= 1;
    }
    return *min_element(cnt, cnt + 26) >= 0;
  }
};

// Accepted
// 127/127 cases passed (10 ms)
// Your runtime beats 95.81 % of cpp submissions
// Your memory usage beats 97.37 % of cpp submissions (8.6 MB)
// @lc code=end

