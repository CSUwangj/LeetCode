/*
 * @lc app=leetcode id=1465 lang=cpp
 *
 * [1465] Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 */

// @lc code=start
const int MOD = 1e9 + 7;
class Solution {
public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    int maxH = 0;
    int maxW = 0;
    int curH = 0;
    int curW = 0;
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    for(auto h : horizontalCuts) {
      maxH = max(maxH, h - curH);
      curH = h;
    }
    maxH = max(maxH, h - curH);
    for(auto w : verticalCuts) {
      maxW = max(maxW, w - curW);
      curW = w;
    }
    maxW = max(maxW, w - curW);
    return 1LL * maxH * maxW % MOD;
  }
};
// @lc code=end

