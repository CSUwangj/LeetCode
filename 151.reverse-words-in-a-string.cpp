/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
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
  string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int len = s.length();
    bool hasSpace = true;
    int newLength = 0;
    for(int i = 0; i < len; ++i) {
      if(s[i] != ' ' || !hasSpace) {
        if(s[i] == ' ') hasSpace = true;
        else hasSpace = false;
        s[newLength] = s[i];
        newLength += 1;
      }
    }
    if(!newLength) return "";
    if(s[newLength-1] == ' ') newLength -= 1;
    s.resize(newLength);
    len = newLength;
    int begin = -1, end = -1;
    for(int i = 0; i < len; ++i) {
      if(s[i] != ' ') {
        if(begin == -1) begin = i;
        end = i+1;
      } else {
        if(begin != -1 && begin != end-1) {
          reverse(s.begin() + begin, s.begin() + end);
        }
        begin = -1;
        end = -1;
      }
    }
    if(begin != -1 && begin != end-1) reverse(s.begin() + begin, s.begin() + end);
    return move(s);
  }
};

// Accepted
// 57/57 cases passed (8 ms)
// Your runtime beats 42.75 % of cpp submissions
// Your memory usage beats 80.89 % of cpp submissions (7.1 MB)
// @lc code=end

