/*
 * @lc app=leetcode id=1870 lang=cpp
 *
 * [1870] Minimum Speed to Arrive on Time
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
  const double EPS = 1e-10;
  bool satisfy(const vector<int>& dist, double hour, double speed) {
    double result = 0;
    for(int i = 0; i + 1 < dist.size(); ++i) {
      result += max<double>(1, ceil(dist[i] / speed));
    }
    result += dist.back() / speed;
    return result <= hour;
  }
public:
  int minSpeedOnTime(vector<int>& dist, double hour) {
    if(dist.size() > hour + 1) return -1;
    int high = 100000000;
    int low = 0;
    while(high > low) {
      double mid = (high + low) / 2;
      if(satisfy(dist, hour, mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return low > 1e7 ? -1 : low;
  }
};

// Accepted
// 65/65 cases passed (275 ms)
// Your runtime beats 92.81 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (101.1 MB)
// @lc code=end

