/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
auto speedup = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    nth_element(points.begin(), points.begin() + k - 1, points.end(), [&](const vector<int> &a, const vector<int> &b) {
      return a[0] * a[0] + a[1] * a[1] <
             b[0] * b[0] + b[1] * b[1];
    });
    points.resize(k);
    return points;
  }
};

// Accepted
// 85/85 cases passed (112 ms)
// Your runtime beats 99.66 % of cpp submissions
// Your memory usage beats 98.48 % of cpp submissions (49 MB)
// @lc code=end

