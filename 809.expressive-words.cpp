/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  bool expressiveWord(string &s, string&t) {
    int sLen = s.length();
    int tLen = t.length();
    int sPos = 0;
    int tPos = 0;
    while(sPos < sLen && tPos < tLen) {
      char sC = s[sPos];
      int sCnt = 0;
      while(sPos < sLen && s[sPos] == sC) {
        sCnt += 1;
        sPos += 1;
      }
      char tC = t[tPos];
      int tCnt = 0;
      while(tPos < tLen && t[tPos] == tC) {
        tCnt += 1;
        tPos += 1;
      }
      if(tC != sC || tCnt > sCnt || (tCnt == 1 && sCnt == 2)) return false;
    }
    return sPos == sLen && tPos == tLen;
  }
public:
  int expressiveWords(string s, vector<string>& words) {
    int answer = 0;
    for(auto &t : words) {
      answer += expressiveWord(s, t);
    }
    return answer;
  }
};

// Accepted
// 34/34 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 82.68 % of cpp submissions (7.6 MB)
// @lc code=end

