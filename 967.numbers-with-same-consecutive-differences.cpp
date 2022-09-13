/*
 * @lc app=leetcode id=967 lang=cpp
 *
 * [967] Numbers With Same Consecutive Differences
 */

// @lc code=start
class Solution {
  void solve(
    vector<int> &answer,
    int current,
    int k,
    int rest
  ) {
    if(!rest) {
      answer.push_back(current);
      return;
    }
    if(current % 10 >= k) {
      solve(answer, current * 10 + current % 10 - k, k, rest - 1);
    }
    if(k && current % 10 + k < 10) {
      solve(answer, current * 10 + current % 10 + k, k, rest - 1);
    }
  }
public:
  vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> answer;
    for(int i = 1; i < 10; ++i) {
      solve(answer, i, k, n - 1);
    }
    return answer;
  }
};

// Accepted
// 81/81 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 49.91 % of cpp submissions (8.7 MB)
// @lc code=end

