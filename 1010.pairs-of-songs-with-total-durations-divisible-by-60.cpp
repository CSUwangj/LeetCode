/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
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
  int numPairsDivisibleBy60(vector<int>& time) {
    int times[60] = {};
    int answer = 0;
    for(auto t : time) {
      t %= 60;
      answer += times[(60 - t) % 60];
      times[t] += 1;
    }
    return answer;
  }
};

// Accepted
// 34/34 cases passed (16 ms)
// Your runtime beats 99.59 % of cpp submissions
// Your memory usage beats 60.38 % of cpp submissions (23.1 MB)
// @lc code=end