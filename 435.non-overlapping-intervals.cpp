/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
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
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[1] < b[1] ||(a[1] == b[1] && a[0] < b[0]);
    });

    int end = -100000;
    int answer = 0;
    for(const auto &interval : intervals) {
      if(interval[0] < end) {
        answer += 1;
      } else {
        end = interval[1];
      }
    }

    return answer;
  }
};

// Accepted
// 58/58 cases passed (478 ms)
// Your runtime beats 70.68 % of cpp submissions
// Your memory usage beats 99.9 % of cpp submissions (88.8 MB)
// @lc code=end

