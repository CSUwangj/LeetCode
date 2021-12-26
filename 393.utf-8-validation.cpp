/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
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
  bool validUtf8(vector<int>& data) {
    int pos = 0;
    int len = data.size();
    while(pos < len) {
      int curPos = pos;
      if(!(data[pos] & 0b10000000)) {
        pos += 1;
      } else {
        for(int i = 2; i < 5; ++i) {
          int mask = (1 << i) - 1;
          // not have first n's 1 or not have (n + 1)'s bit as 0
          if(((data[pos] >> (8 - i)) & mask) != mask || ((data[pos] >> (7 - i)) & 1)) continue;
          if(pos > len - i) return false;
          for(int j = 1; j < i; ++j) {
            cout << i << ' ' << data[pos + j] << endl;
            if((data[pos + j] & 0b11000000) != 0b10000000) return false;
          }
          pos += i;
          break;
        }
      }
      if(pos == curPos) return false;
    }
    return true;
  }
};

// Accepted
// 49/49 cases passed (8 ms)
// Your runtime beats 92.07 % of cpp submissions
  // Your memory usage beats 7.65 % of cpp submissions (14.1 MB)
// @lc code=end
