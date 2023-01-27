/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
public:
  int maxPoints(vector<vector<int>>& points) {
    int len = points.size();
    if(len < 3) return len;
    int answer = 0;
    for(int i = 0; i < len - 1; ++i) {
      map<double, int> count;
      int overlap = 0;
      int y = 0;
      for(int j = 0; j < len; ++j) {
        if(i == j) continue;
        int dx = points[i][0] - points[j][0];
        int dy = points[i][1] - points[j][1];
        if(dx == 0 && dy == 0) {
          overlap += 1;
        }else if (dy == 0) {
          y += 1;
        } else {
          count[dx * 1.0 / dy] += 1;
        }
      }
      for(const auto &[_, c] : count) {
        answer = max(answer, 1 + overlap + c);
      }
      answer = max(answer, 1 + y);
    }
    return answer;
  }
};

// Accepted
// 35/35 cases passed (48 ms)
// Your runtime beats 80.56 % of cpp submissions
// Your memory usage beats 37.28 % of cpp submissions (17.4 MB)
// @lc code=end

