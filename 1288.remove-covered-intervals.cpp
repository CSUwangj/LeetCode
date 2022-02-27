/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
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
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    });
    int removed = 0;
    int end = -1;
    for(const auto &interval : intervals) {
      if(interval[1] <= end) {
        removed += 1;
      } else {
        end = interval[1];
      }
    }
    return intervals.size() - removed;
  }
};

// Accepted
// 34/34 cases passed (45 ms)
// Your runtime beats 31.8 % of cpp submissions
// Your memory usage beats 59.43 % of cpp submissions (11.4 MB)
// @lc code=end
