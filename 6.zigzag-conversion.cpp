/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
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
  string convert(string s, int numRows) {
    if(numRows == 1) return s;
    int len = s.length();
    string answer;
    for(int row = 0; row < numRows; ++row) {
      for(int pos = row; pos < len; pos += 2 * numRows - 2) {
        answer.push_back(s[pos]);
        if(!row || row == numRows - 1) continue;

        if(pos + 2 * (numRows - row - 1) < len) {
          answer.push_back(s[pos + 2 * (numRows - row - 1)]);
        }
      }
    }
    return answer;
  }
};

// Accepted
// 1157/1157 cases passed (15 ms)
// Your runtime beats 41.89 % of cpp submissions
// Your memory usage beats 65.47 % of cpp submissions (8.3 MB)
// @lc code=end
