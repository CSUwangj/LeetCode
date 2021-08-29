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
    int cnt = 0, min_end = -1;
    bool hasBalloon = false;
    for(int i = 0; i < points.size(); ++i) {
      if(!hasBalloon) {
        min_end = points[i][1];
        hasBalloon = true;
      } else {
        if(points[i][0] > min_end) {
          cnt += 1;
          hasBalloon = true;
          min_end = points[i][1];
        } else {
          min_end = min(points[i][1], min_end);
        }
      }
    }
    if(hasBalloon) cnt += 1;
    return cnt;
  }
};

// Accepted
// 44/44 cases passed (112 ms)
// Your runtime beats 94.94 % of cpp submissions
// Your memory usage beats 62.92 % of cpp submissions (34.9 MB)
// @lc code=end

