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
    vector<vector<int>> answer;
    vector<int> index;
    for(int i = 0; i < points.size(); ++i) index.push_back(i);
    nth_element(index.begin(), index.begin() + k - 1, index.end(), [&](int a, int b) {
      return points[a][0] * points[a][0] + points[a][1] * points[a][1] <
             points[b][0] * points[b][0] + points[b][1] * points[b][1];
    });
    for(int i = 0; i < k; ++i) answer.push_back(points[index[i]]);
    return answer;
  }
};

// Accepted
// 84/84 cases passed (108 ms)
// Your runtime beats 99.8 % of cpp submissions
// Your memory usage beats 73.75 % of cpp submissions (53.3 MB)
// @lc code=end

