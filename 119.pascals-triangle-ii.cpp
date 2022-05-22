/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
constexpr int combination(int m, int n) {
  m = n - m > m ? m : n - m;
  long long result = 1;
  for(int i = 0; i < m; ++i) {
    result *= n - i;
    result /= i + 1;
  }
  return result;
}
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> answer(rowIndex + 1);
    for(int i = 0; i <= rowIndex; ++i) {
      answer[i] = combination(i, rowIndex);
    }
    return answer;
  }
};

// Accepted
// 34/34 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 52.72 % of cpp submissions (6.4 MB)
// @lc code=end
