/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
  vector<int> grayCode(int n) {
    int sz = 1 << n;
    vector<int> answer(sz);
    for(int i = 1; i <= n; ++i) {
      int bound = 1 << i;
      for(int j = 0; j * 2 < bound; ++j) {
        answer[bound - j - 1] = answer[j] | (bound >> 1);
      }
    }
    return answer;
  }
};
// @lc code=end

