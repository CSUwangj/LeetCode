/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
using ll = long long;
class Solution {
  int len;
  long long target;
  bool solve(vector<int> &m, ll a, ll b, ll c, ll d, ll l) {
    if(l == len && a == target && b == target && c == target && d == target) {
      return true;
    }
    if(a > target || b > target || c > target || d > target) {
      return false;
    }
    if(solve(m, a + ll(m[l]), b, c, d, l + 1)) return true;
    if(solve(m, a, b + ll(m[l]), c, d, l + 1)) return true;
    if(solve(m, a, b, c + ll(m[l]), d, l + 1)) return true;
    return solve(m, a, b, c, d + ll(m[l]), l + 1);
  }
public:
  bool makesquare(vector<int>& matchsticks) {
    len = matchsticks.size();
    if(len < 4) return false;
    sort(matchsticks.rbegin(), matchsticks.rend());
    long long sum = 0;
    for(auto l : matchsticks) sum += l;
    if(sum % 4 || matchsticks.back() > sum / 4) return false;
    target = sum / 4;
    return solve(matchsticks, 0, 0, 0, 0, 0); 
  }
};
// @lc code=end

