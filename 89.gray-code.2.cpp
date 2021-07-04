/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
#define gray(x) (x ^ (x >> 1))
class Solution {
public:
  vector<int> grayCode(int n) {
    int sz = 1 << n;
    vector<int> answer(sz);
    for(int i = 0; i < sz; ++i) {
      answer[i] = gray(i);
    }
    return answer;
  }
};
// @lc code=end

