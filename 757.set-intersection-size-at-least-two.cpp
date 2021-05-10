/*
 * @lc app=leetcode id=757 lang=cpp
 *
 * [757] Set Intersection Size At Least Two
 */

// @lc code=start
class Solution {
public:
  int intersectionSizeTwo(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
    });
    int answer = 0;
    pair<int, int> pre = {-1, -1};
    for(auto &i : intervals) {
      if(pre.second == -1 || pre.second < i[0]) {
        answer += 2;
        pre.first = i[1] - 1;
        pre.second = i[1];
      } else if(pre.first < i[0]) {
        pre.first = pre.second;
        pre.second = i[1];
        answer += 1;
      }
    }
    return answer;
  }
};
// @lc code=end

