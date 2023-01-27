/*
 * @lc app=leetcode id=2244 lang=cpp
 *
 * [2244] Minimum Rounds to Complete All Tasks
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
  int minimumRounds(vector<int>& tasks) {
    map<int, int> count;
    for(auto task : tasks) {
      count[task] += 1;
    }
    int answer = 0;
    for(const auto &[_, c] : count) {
      if(c == 1) return -1;
      int result = INT_MAX;
      if(c % 2 == 0) {
        result = c / 2;
      }
      if((c - 4 > 0 && (c - 4) % 3 == 0) || (c - 2 > 0 && (c - 2) % 3 == 0)) {
        result = c / 3 + 1;
      }
      if(c % 3 == 0) {
        result = c / 3;
      }
      answer += result;
    }
    return answer;
  }
};

// Accepted
// 79/79 cases passed (276 ms)
// Your runtime beats 66.53 % of cpp submissions
// Your memory usage beats 23.86 % of cpp submissions (104.7 MB)
// @lc code=end

