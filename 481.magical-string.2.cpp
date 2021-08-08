/*
 * @lc app=leetcode id=481 lang=cpp
 *
 * [481] Magical String
 */

// @lc code=start
int result[100001] = {1};
auto speedup = [](){
  int n = 100000;
  int pos = 2;
  int end = 3;
  bool isTwo = false;
  while(end < n) {
    if(isTwo) {
      end += 2 - result[pos];
    } else {
      result[end++] = true;
      if(!result[pos]) result[end++] = true;
    }
    isTwo = !isTwo;
    pos += 1;
  }
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int magicalString(int n) {
    return accumulate(result, result + n, 0);
  }
};

// Accepted
// 64/64 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 82.78 % of cpp submissions (6.6 MB)
// @lc code=end

