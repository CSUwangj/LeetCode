/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */

// @lc code=start
class Solution {
public:
  vector<int> sumZero(int n) {
    vector<int> answer(n);
    for(int i = 0; i * 2 + 1 < n; ++i) {
      answer[i * 2] = i + 1;
      answer[i * 2 + 1] = -i - 1;
    }
    return move(answer);
  }
};
// @lc code=end

