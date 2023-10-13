/*
 * @lc app=leetcode id=2141 lang=cpp
 *
 * [2141] Maximum Running Time of N Computers
 */

// @lc code=start
class Solution {
  using ll = long long;
public:
  ll maxRunTime(int n, vector<int>& batteries) {
    ll low = 1;
    ll high = accumulate(batteries.begin(), batteries.end(), 0LL) / n;

    while(low < high) {
      ll mid = (low + high + 1) / 2;
      ll time = 0;
      for(auto battery : batteries) {
        time += min<ll>(battery, mid);
      }

      if(mid * n <= time) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};

// Accepted
// 52/52 cases passed (140 ms)
// Your runtime beats 99.64 % of cpp submissions
// Your memory usage beats 71.58 % of cpp submissions (55.7 MB)
// @lc code=end

