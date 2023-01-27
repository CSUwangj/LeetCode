/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
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
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.insert(lower_bound(intervals.begin(), intervals.end(), newInterval), newInterval);
    intervals.push_back({100002, -1});
    int len = intervals.size();
    int pos = 0;
    int begin = intervals.front()[0];
    int end = intervals.front()[1];
    for(int i = 0; i < len; ++i) {
      if(intervals[i][0] <= end) {
        end = max(end, intervals[i][1]);
      } else {
        intervals[pos][0] = begin;
        intervals[pos][1] = end;
        pos += 1;
        begin = intervals[i][0];
        end = intervals[i][1];
      }
    }
    intervals.resize(pos);
    return intervals;
  }
};

// Accepted
// 156/156 cases passed (16 ms)
// Your runtime beats 83.48 % of cpp submissions
// Your memory usage beats 92.65 % of cpp submissions (17 MB)
// @lc code=end
