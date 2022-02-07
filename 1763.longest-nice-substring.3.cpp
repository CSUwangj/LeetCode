/*
 * @lc app=leetcode id=1763 lang=cpp
 *
 * [1763] Longest Nice Substring
 */

// @lc code=start
class Solution {
  pair<int, int> solve(const string &s, int begin, int end) {
    // cout << begin << ' ' << end << endl;
    if(end - begin < 2) return {0, 0};
    int lower = 0;
    int upper = 0;
    for(int i = begin; i < end; ++i) {
      if(isupper(s[i])) {
        upper |= 1 << (s[i] - 'A');
      } else {
        lower |= 1 << (s[i] - 'a');
      }
    }
    int rest = upper ^ lower;
    if(!rest) return {begin, end - begin};
    pair<int, int> answer{0, 0};
    int prev = begin - 1;
    for(int i = begin; i < end; ++i) {
      if(!(rest & (1 << (toupper(s[i]) - 'A')))) continue;
      auto result = solve(s, prev + 1, i);
      prev = i;
      if(result.second > answer.second) answer = result;
    }
    auto result = solve(s, prev + 1, end);
    if(result.second > answer.second) answer = result;
    return answer;
  }
public:
  string longestNiceSubstring(string s) {
    auto [begin, len] = solve(s, 0, s.length());
    return s.substr(begin, len);
  }
};

// Accepted
// 73/73 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 97.08 % of cpp submissions (6.1 MB)
// @lc code=end
