/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */

// @lc code=start
class Solution {
public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int dx = coordinates[1][0] - coordinates[0][0];
    int dy = coordinates[1][1] - coordinates[0][1];
    bool result = true;
    for(int i = 2; i < coordinates.size() && result; ++i) {
      int ndx = coordinates[i][0] - coordinates[0][0];
      int ndy = coordinates[i][1] - coordinates[0][1];
      if(dx && ndy * dx != ndx * dy) result = false;
      if(!dx && ndx) result = false;
    }

    return result;
  }
};

// Accepted
// 79/79 cases passed (7 ms)
// Your runtime beats 90.62 % of cpp submissions
// Your memory usage beats 63.27 % of cpp submissions (10 MB)
// @lc code=end

