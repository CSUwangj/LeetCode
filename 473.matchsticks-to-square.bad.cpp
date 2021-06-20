/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
  vector<bool> used;
  int len;
  long long target;
  bool solve(vector<int> &m, int cnt, int rest) {
    // cout << cnt << ' ' << rest << endl;
    if(cnt == len) return true;
    for (int i = 0; i < len; ++i) {
      if(used[i] || rest < m[i]) continue;
      used[i] = true;
      if(solve(m, cnt + 1, rest - m[i] ? rest - m[i] : target)) return true;
      used[i] = false;
    }
    return false;
  }
public:
  bool makesquare(vector<int>& matchsticks) {
    sort(matchsticks.rbegin(), matchsticks.rend());
    long long sum = 0;
    for(auto l : matchsticks) sum += l;
    if(sum % 4 || matchsticks.back() > sum / 4) return false;
    target = sum / 4;
    len = matchsticks.size();
    used.resize(len);
    return solve(matchsticks, 0, target); 
  }
};
// @lc code=end

