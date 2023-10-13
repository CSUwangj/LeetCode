/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
int vowel[128] = {
  ['a'] = 1,
  ['e'] = 1,
  ['i'] = 1,
  ['o'] = 1,
  ['u'] = 1
};
class Solution {
public:
  int maxVowels(string s, int k) {
    int pos = 0;
    int answer = 0;
    int count = 0;
    for(; pos < k; ++pos) {
      count += vowel[s[pos]];
    }
    answer = max(answer, count);
    for(;pos < s.length(); ++pos) {
      count += vowel[s[pos]];
      count -= vowel[s[pos - k]];
      answer = max(answer, count);
    }

    return answer;
  }
};

// Accepted
// 106/106 cases passed (11 ms)
// Your runtime beats 99.57 % of cpp submissions
// Your memory usage beats 29.12 % of cpp submissions (10 MB)
// @lc code=end

