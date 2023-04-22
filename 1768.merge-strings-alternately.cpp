/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    int pos = 0;

    string answer;
    answer.reserve(len1 + len2);
    for(; pos < len1 && pos < len2; ++pos) {
      answer.push_back(word1[pos]);
      answer.push_back(word2[pos]);
    }
    for(; pos < len1; ++pos) {
      answer.push_back(word1[pos]);
    }
    for(; pos < len2; ++pos) {
      answer.push_back(word2[pos]);
    }

    return answer;
  }
};

// Accepted
// 108/108 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 60.87 % of cpp submissions (6.4 MB)
// @lc code=end

