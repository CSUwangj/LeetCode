/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
constexpr int highbit(int x) {
  x |= x >> 16;
  x |= x >> 8;
  x |= x >> 4;
  x |= x >> 2;
  x |= x >> 1;
  x ^= x >> 1;
  return x;
}
class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    if(left == right) return left;
    int result = left & right;
    int answer = 0;
    int bit = highbit(right);
    while(bit) {
      if(bit & result) {
        answer |= bit;
      } else if((bit & left) || (bit & right)) {
        break;
      }
      bit >>= 1;
    }
    return answer;
  }
};

// Accepted
// 8268/8268 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 77.49 % of cpp submissions (5.9 MB)
// @lc code=end

