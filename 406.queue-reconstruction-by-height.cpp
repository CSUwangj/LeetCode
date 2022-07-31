/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    });
    vector<vector<int>> answer;
    for(const auto &p : people) {
      answer.insert(answer.begin() + p[1], p);
    }
    return move(answer);
  }
};

// Accepted
// 36/36 cases passed (271 ms)
// Your runtime beats 25.57 % of cpp submissions
// Your memory usage beats 63.86 % of cpp submissions (12 MB)
// @lc code=end

