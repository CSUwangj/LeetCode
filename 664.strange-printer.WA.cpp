/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */

// @lc code=start
class Solution {
  int solve(string &s, int start, int end, char outer = 0) {
    if(start > end) return 0;
    if(start == end) return 1;
    int result = 0;
    while(start <= end) {
      char current = s[start];
      int last = start;
      int count = 0;
      for(int i = start; i <= end; ++i) {
        if(s[i] == current) {
          last = i;
          count += 1;
        }
      }
      int newStart = start;
      int newEnd = last;
      while(newStart <= newEnd && s[newStart] == current) newStart += 1;
      while(newStart <= newEnd && s[newEnd] == current) newEnd -= 1;
      result += (outer == current) + solve(s, newStart, newEnd, current);
      start = last + 1;
    }
    return result;
  }
public:
  int strangePrinter(string s) {
    int len = s.length();
    return solve(s, 0, len - 1);
  }
};
// @lc code=end

