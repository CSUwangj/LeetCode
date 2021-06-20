/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
  int len;
  int target;
  int sides[4] = {};
  bool solve(vector<int> &m, int index) {
    if(index == len) return true;
    for(int i = 0; i < 4; ++i) {
      if([&](){
        for(int j = 0; j < i; ++j) {
          if(sides[j] == sides[i]) return true;
        }
        return false;
      }()) continue;
      if(sides[i] + m[index] > target) continue;
      sides[i] += m[index];
      if(solve(m, index + 1)) return true;
      sides[i] -= m[index];
    }
    return false;
  }
public:
  bool makesquare(vector<int>& matchsticks) {
    len = matchsticks.size();
    if(len < 4) return false;
    sort(matchsticks.rbegin(), matchsticks.rend());
    int sum = 0;
    for(auto l : matchsticks) sum += l;
    if(sum % 4 || matchsticks.back() > sum / 4) return false;
    target = sum / 4;
    return solve(matchsticks, 0); 
  }
};
// @lc code=end

