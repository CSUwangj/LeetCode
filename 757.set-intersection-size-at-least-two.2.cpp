/*
 * @lc app=leetcode id=757 lang=cpp
 *
 * [757] Set Intersection Size At Least Two
 */

// @lc code=start
class Solution {
public:
  int intersectionSizeTwo(vector<vector<int>>& intervalsVector) {
    vector<pair<int, int>> intervals;
    for(auto &interval : intervalsVector) {
      intervals.push_back(make_pair(interval[0], interval[1]));
    }
    sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.second < b.second || (a.second == b.second && a.first > b.first);
    });
    int answer = 0;
    pair<int, int> pre = {-1, -1};
    for(auto [start, end] : intervals) {
      if(pre.second == -1 || pre.second < start) {
        answer += 2;
        pre.first = end - 1;
        pre.second = end;
      } else if(pre.first < start) {
        pre = {pre.second, end};
        answer += 1;
      }
    }
    return answer;
  }
};
// @lc code=end

