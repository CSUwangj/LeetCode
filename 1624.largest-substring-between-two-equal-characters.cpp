/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

// @lc code=start
int front[26];
int back[26];
class Solution {
public:
  int maxLengthBetweenEqualCharacters(string s) {
    for(int i = 0; i < 26; ++i) {
      front[i] = 1000;
      back[i] = -1000;
    }
    for(int i = 0; i < s.length(); ++i) {
      int c = s[i] - 'a';
      front[c] = min(front[c], i);
      back[c] = max(back[c], i);
    }
    int answer = -1;
    for(int i = 0; i < 26; ++i) {
      answer = max(answer, back[i] - 1 - front[i]);
    }
    return answer;
  }
};

// Accepted
// 54/54 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 86.26 % of cpp submissions (6.2 MB)
// @lc code=end

