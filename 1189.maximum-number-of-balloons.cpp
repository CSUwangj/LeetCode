/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
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
  int maxNumberOfBalloons(string text) {
    int cnt[128] = {};
    for(auto c : text) {
      cnt[c] += 1;
    }

    int answer = INT_MAX;
    answer = min(answer, cnt['b']);
    answer = min(answer, cnt['a']);
    answer = min(answer, cnt['n']);
    answer = min(answer, cnt['l'] / 2);
    answer = min(answer, cnt['o'] / 2);

    return answer;
  }
};

// Accepted
// 24/24 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 85.28 % of cpp submissions (6.6 MB)
// @lc code=end

