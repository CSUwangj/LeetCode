/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int sLen = s.length();
    int pLen = p.length();
    if(sLen < pLen) return {};
    vector<int> target(26);
    for(auto c : p) {
      target[c - 'a'] += 1;
    }
    vector<int> current(26);
    for(int i = 0; i < pLen; ++i) {
      current[s[i] - 'a'] += 1;
    }
    vector<int> answer;
    for(int i = pLen; i < sLen; ++i) {
      if(current == target) answer.push_back(i - pLen);
      current[s[i] - 'a'] += 1;
      current[s[i - pLen] - 'a'] -= 1;
    }
    if(current == target) answer.push_back(sLen - pLen);
    return answer;
  }
};

// Accepted
// 61/61 cases passed (8 ms)
// Your runtime beats 97.21 % of cpp submissions
// Your memory usage beats 90.96 % of cpp submissions (8.6 MB)
// @lc code=end
