/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
class Solution {
public:
  int minFlips(int a, int b, int c) {
    int answer = 0;
    while(a || b || c) {
      if(c & 1) {
        answer += !((a|b)&1);
      } else {
        answer += (a&1) + (b&1);
      }
      a >>= 1;
      b >>= 1;
      c >>= 1;
    }
    return answer;
  }
};

// Accepted
// 64/64 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 93.33 % of cpp submissions (5.9 MB)
// @lc code=end

