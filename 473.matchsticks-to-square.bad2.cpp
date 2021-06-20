/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
  bitset<15> used;
  int len;
  bool solve(vector<int> &m, int index, int rest) {
    if(!rest) return true;
    for (int i = index; i < len; ++i) {
      if(used[i] || rest < m[i]) continue;
      used[i] = true;
      if(solve(m, i + 1, rest - m[i])) return true;
      used[i] = false;
    }
    return false;
  }
public:
  bool makesquare(vector<int>& matchsticks) {
    len = matchsticks.size();
    if(len < 4) return false;
    int sum = 0;
    for(auto l : matchsticks) sum += l;
    if(sum % 4 || matchsticks.back() > sum / 4) return false;
    sort(matchsticks.begin(), matchsticks.end(), greater<int>());
    int target = sum / 4;
    
    for(int i = 0; i < 4; ++i) {
      if(!solve(matchsticks, 0, target)) return false;
    }
    return true;
  }
};
// @lc code=end

