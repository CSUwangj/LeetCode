/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    int count = 1;
    int minEnd = points.front()[1];
    for(const auto &point : points) {
      if(point[0] > minEnd) {
        count += 1;
        minEnd = point[1];
      } else {
        minEnd = min(point[1], minEnd);
      }
    }
    return count;
  }
};

// Accepted
// 48/48 cases passed (541 ms)
// Your runtime beats 34.25 % of cpp submissions
// Your memory usage beats 99.9 % of cpp submissions (89.4 MB)
// @lc code=end

