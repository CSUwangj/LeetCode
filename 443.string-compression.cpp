/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution {
public:
  int compress(vector<char>& chars) {
    int newPos = 0;
    int len = chars.size();
    int pos = 0;
    while(pos < len) {
      chars[newPos] = chars[pos];
      int cnt = 0;
      while(pos < len && chars[pos] == chars[newPos]) {
        pos += 1;
        cnt += 1;
      }
      newPos += 1;
      if(cnt == 1) continue;
      string count = to_string(cnt);
      for(auto it = count.begin(); it != count.end(); ++it) chars[newPos++] = *it;
    }
    return newPos;
  }
};

// Accepted
// 73/73 cases passed (6 ms)
// Your runtime beats 53.56 % of cpp submissions
// Your memory usage beats 42.12 % of cpp submissions (9 MB)
// @lc code=end

