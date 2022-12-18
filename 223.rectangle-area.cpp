/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
auto speedup = [](){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int x = min({ax2 - bx1, bx2 - ax1, ax2 - ax1, bx2 - bx1});
    if(x < 0) x = 0;
    int y = min({ay2 - by1, by2 - ay1, ay2 - ay1, by2 - by1});
    if(y < 0) y = 0;
    return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - x * y;
  }
};

// Accepted
// 3080/3080 cases passed (15 ms)
// Your runtime beats 57.3 % of cpp submissions
// Your memory usage beats 5.6 % of cpp submissions (6.1 MB)
// @lc code=end

