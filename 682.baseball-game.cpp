/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution {
public:
  int calPoints(vector<string>& ops) {
    vector<int> points;
    for(const auto &op : ops) {
      if (op[0] == 'C') {
        points.pop_back();
      } else if (op[0] == 'D') {
        points.push_back(points.back() * 2);
      } else if (op[0] == '+') {
        points.push_back(points.back() + points[points.size() - 2]);
      } else {
        points.push_back(stoi(op));
      }
    }
    return accumulate(points.begin(), points.end(), 0);
  }
};

// Accepted
// 39/39 cases passed (7 ms)
// Your runtime beats 43.82 % of cpp submissions
// Your memory usage beats 95.63 % of cpp submissions (8.3 MB)
// @lc code=end
