/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
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
  int trap(vector<int>& height) {
    vector<int> maxRights{0};
    int len = height.size();
    for(int i = len - 1; i >= 0; --i) {
      if(height[i] >= maxRights.back()) {
        maxRights.push_back(height[i]);
      }
    }
    int maxLeft = 0;
    int answer = 0;
    for(auto h : height) {
      maxLeft = max(maxLeft, h);
      int maxRight = maxRights.back();
      int waterHeight = maxLeft > maxRight ? maxRight : maxLeft;
      answer += waterHeight > h ? (waterHeight - h) : 0;
      if(h == maxRight) {
        maxRights.pop_back();
      }
    }
    return answer;
  }
};

// Accepted
// 320/320 cases passed (4 ms)
// Your runtime beats 89.31 % of cpp submissions
// Your memory usage beats 54.78 % of cpp submissions (14.2 MB)
// @lc code=end

