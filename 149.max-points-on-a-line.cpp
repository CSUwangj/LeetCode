/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
inline int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}
inline int sgn(int val) {
    return ((0) < val) - (val < (0));
}
class Solution {
public:
  int maxPoints(vector<vector<int>>& points) {
    int len = points.size();
    if(len < 3) return len;
    int answer = 0;
    for(int i = 0; i < len - 1; ++i) {
      map<pair<int, int>, int> count;
      int overlap = 0;
      for(int j = 0; j < len; ++j) {
        if(i == j) continue;
        int dx = points[i][0] - points[j][0];
        int dy = points[i][1] - points[j][1];
        if(dx == 0 && dy == 0) {
          overlap += 1;
        } else if (dx == 0) {
          count[{0, 1}] += 1;
        } else if (dy == 0) {
          count[{1, 0}] += 1;
        } else {
          int g = abs(gcd(dx, dy)) * sgn(dx);
          count[{dx / g, dy / g}] += 1;
        }
      }
      for(const auto &[_, c] : count) {
        answer = max(answer, 1 + overlap + c);
      }
    }
    return answer;
  }
};

// Accepted
// 35/35 cases passed (58 ms)
// Your runtime beats 67.5 % of cpp submissions
// Your memory usage beats 35.72 % of cpp submissions (17.6 MB)
// @lc code=end

