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
// 49/49 cases passed (492 ms)
// Your runtime beats 78.49 % of cpp submissions
// Your memory usage beats 28.76 % of cpp submissions (89.8 MB)
// @lc code=end

