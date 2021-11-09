/*
 * @lc app=leetcode id=1044 lang=cpp
 *
 * [1044] Longest Duplicate Substring
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  string longestDupSubstring(string s) {
    int len = s.length();

    int answerLen = 0;
    int answerStart = 0;
    int start = 0;
    int low = 1;
    int high = len;
    while(low < high) {
      if(answerLen + start >= len) {
        break;
      }
      int mid = (low + high) >> 1;
      for(int start = 0; start + mid < len; ++ start) {
        auto it = search(s.begin() + start + 1, s.end(),
                          boyer_moore_horspool_searcher(
                          s.begin() + start, s.begin() + start + mid));
        if(it != s.end()) {
          answerStart = start;
          answerLen = mid;
          break;
        }
      }
      if(answerLen == mid) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return s.substr(answerStart, answerLen);
  }
};
// @lc code=end

