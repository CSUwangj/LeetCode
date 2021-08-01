/*
 * @lc app=leetcode id=1839 lang=cpp
 *
 * [1839] Longest Substring Of All Vowels in Order
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
class Solution {
public:
  int longestBeautifulSubstring(string word) {
    int len = word.length();
    int vPos = 0;
    int answer = 0;
    int cur = 0;
    int pos = 0;
    while(pos < len) {
      if(word[pos] != vowels[vPos]) {
        if(vPos) vPos = 0;
        else pos += 1;
        cur = 0;
      } else {
        while(pos < len && word[pos] == vowels[vPos]) {
          pos += 1;
          cur += 1;
        }
        vPos += 1;
        if(vPos == 5) {
          answer = max(answer, cur);
          vPos = 0;
          cur = 0;
        }
      }
    }
    return answer;
  }
};

// Accepted
// 120/120 cases passed (51 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 98.36 % of cpp submissions (26.7 MB)
// @lc code=end

