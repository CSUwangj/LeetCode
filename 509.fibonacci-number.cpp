/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
struct mat {
  int val[2][2] = {};
};

const mat base = {
  .val = {{1, 1}, {1, 0}}
};

//  a b  |  1 1 
//  0 0  |  1 0

//  a+b b
//   0  0

constexpr mat multiply(mat a, mat b) {
  mat result;
  result.val[0][0] = a.val[0][0] * b.val[0][0] + a.val[0][1] * b.val[1][0];
  result.val[0][1] = a.val[0][0] * b.val[0][1] + a.val[0][1] * b.val[1][1];
  result.val[1][0] = a.val[1][0] * b.val[0][0] + a.val[1][1] * b.val[1][0];
  result.val[1][1] = a.val[1][0] * b.val[0][1] + a.val[1][1] * b.val[1][1];
  return result;
}

constexpr mat exp(mat b, int e) {
  mat result = {
    .val = {{1, 0}, {0, 1}}
  };
  while(e) {
    if(e & 1) {
      result = multiply(result, b);
    }
    b = multiply(b, b);
    e >>= 1;
  }
  return result;
}

class Solution {
public:
  int fib(int n) {
    mat result = { .val = {{1, 0}, {0, 0}} };
    result = multiply(result, exp(base, n));
    return result.val[0][1];
  }
};

// Accepted
// 31/31 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 80.05 % of cpp submissions (5.9 MB)
// @lc code=end

