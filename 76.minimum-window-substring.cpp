/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  int cnt[128] = {};
public:
  string minWindow(string s, string t) {
    int chars = 0;
    for(auto c : t) {
      chars += !cnt[c];
      cnt[c] += 1;
    }
    int end = 0;
    int sLen = s.length();
    while(end < sLen && chars) {
      cnt[s[end]] -= 1;
      chars -= !cnt[s[end]];
      end += 1;
    }
    if(chars) return "";
    int resultLen = INT_MAX;
    int resultBegin = 0;
    for(int begin = 0; begin < end; ++begin) {
      if(end - begin < resultLen) {
        resultLen = end - begin;
        resultBegin = begin;
      }
      cnt[s[begin]] += 1;
      while(end < sLen && cnt[s[begin]] > 0) {
        cnt[s[end]] -= 1;
        end += 1;
      }
      if(cnt[s[begin]] > 0) break;
    }
    return s.substr(resultBegin, resultLen);
  }
};

// Accepted
// 266/266 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 80.15 % of cpp submissions (7.7 MB)
// @lc code=end

