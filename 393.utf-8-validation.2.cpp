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
  bool validUtf8(vector<int>& a) {
    int count=0;
    for(auto val: a) {
      if(count == 0) {
        if(!(val >> 7)) {
          count = 0;
        } else if((val >> 5) == 0b110) {
          count = 1;
        } else if((val >> 4) == 0b1110) {
          count = 2;
        } else if((val >> 3) == 0b11110) {
          count = 3;
        } else return false; 
      } else {
        if((val >> 6) == 0b10) {
          count -= 1;
        } else return false;
      }
    }
    return !count;
  }
};

// Accepted
// 49/49 cases passed (8 ms)
// Your runtime beats 92.07 % of cpp submissions
// Your memory usage beats 7.65 % of cpp submissions (14.2 MB)
// @lc code=end
