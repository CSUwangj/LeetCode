/*
 * @lc app=leetcode id=2225 lang=cpp
 *
 * [2225] Find Players With Zero or One Losses
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
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    map<int, int> lost;
    for(const auto &match: matches) {
      lost[match[0]] += 0;
      lost[match[1]] += 1;
    }
    vector<vector<int>> answer(2);
    for(const auto &[player, losses] : lost) {
      if(!losses) {
        answer[0].push_back(player);
      } else if(losses == 1) {
        answer[1].push_back(player);
      }
    }
    return answer;
  }
};

// Accepted
// 127/127 cases passed (1056 ms)
// Your runtime beats 75.36 % of cpp submissions
// Your memory usage beats 88.88 % of cpp submissions (162.2 MB)
// @lc code=end

